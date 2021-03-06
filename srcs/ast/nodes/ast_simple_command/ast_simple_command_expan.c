/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "expan/expansion.h"
#include "shenv/shenv.h"
#include "token/token_mgr.h"
#include "pattern_matching/pattern.h"
#include "pattern_matching/brace/brace.h"

static void		iter_cmd_fn(void *token, void *context)
{
	t_expansion				*expansion;
	t_ast_simple_command	*cmd;
	t_lst					*expanded;
	t_lst					*token_expanded_sequel;

	cmd = context;
	expansion = expansion_new_from_token(token);
	expanded = expansion_get_fields_simple_command(expansion);
	if (expansion->error)
	{
		shenv_singl_error(0, "%s", expansion->error);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		expansion_del(expansion);
		twl_lst_del(expanded, free);
		return ;
	}
	token_expanded_sequel = token_mgr_new_from_string_list(token, expanded);
	twl_lst_extend(cmd->cmd_tokens_expanded, token_expanded_sequel);
	twl_lst_del(token_expanded_sequel, NULL);
	twl_lst_del(expanded, free);
	expansion_del(expansion);
}

static void		iter_assign_fn(void *data, void *context)
{
	t_expansion				*expansion;
	t_ast_simple_command	*cmd;
	t_ast_assignment		*assign;
	char					*expanded;

	assign = data;
	cmd = context;
	expansion = expansion_new_from_text(assign->value_unexpanded);
	expanded = expansion_get_string_assign(expansion);
	if (expansion->error)
	{
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	if (assign->value)
		free(assign->value);
	assign->value = expanded;
	expansion_del(expansion);
	(void)cmd;
}

static void		iter_redir_fn_end(t_expansion *expansion, t_ast_redir *redir,
		t_lst *expanded)
{
	expansion_del(expansion);
	if (twl_lst_len(expanded) != 1)
	{
		shenv_singl_error(0, "%s: ambiguous redirect",
				redir->param->text_unexpanded);
		shenv_singleton()->last_exit_code = 1;
		twl_lst_del(expanded, free);
		return ;
	}
	token_set_text(redir->param, twl_lst_first(expanded));
	twl_lst_del(expanded, free);
}

static void		iter_redir_fn(void *data)
{
	t_expansion				*expansion;
	t_ast_redir				*redir;
	t_lst					*expanded;

	redir = data;
	if (redir->heredoc_text)
	{
		ast_simple_command_expan_heredoc(redir);
		return ;
	}
	expansion = expansion_new_from_token(redir->param);
	expanded = expansion_get_fields_redir(expansion);
	if (expansion->error)
	{
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	iter_redir_fn_end(expansion, redir, expanded);
}

void			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	cmd->cmd_tokens_expanded = twl_lst_new();
	if (!cmd->cmd_tokens_braced)
	{
		cmd->cmd_tokens_braced = brace_expand_tokens(cmd->cmd_tokens_deep_copy);
	}
	twl_lst_iter(cmd->cmd_tokens_braced, iter_cmd_fn, cmd);
	twl_lst_iter0(cmd->redir_items, iter_redir_fn);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
}
