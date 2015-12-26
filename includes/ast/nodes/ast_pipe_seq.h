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

#ifndef AST_PIPE_SEQ_H
# define AST_PIPE_SEQ_H

# include "basics.h"

# include "token_mgr.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_cmd_seq.h"

typedef struct		s_ast_pipe_seq
{
	t_lst			*tokens;
	t_lst			*ast_cmd_seq_lst;
}					t_ast_pipe_seq;

t_ast_pipe_seq			*ast_pipe_seq_new(void);
void				ast_pipe_seq_del(t_ast_pipe_seq *ast_pipe_seq);

t_ast_pipe_seq		*ast_pipe_seq_new_from_tokens(t_lst *tokens);
void				ast_pipe_seq_print_rec(t_ast_pipe_seq *ast_pipe_seq, int depth);

bool				ast_pipe_seq_is_delimiter(t_token *tokens);

#endif
