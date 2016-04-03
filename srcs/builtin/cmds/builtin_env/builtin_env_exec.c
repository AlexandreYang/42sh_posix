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

#include "builtin/cmds/builtin_env.h"
#include "ast/ast.h"


static void			exec_remaining_command(t_argparser_result *argparser_result)
{
	if (argparser_result_opt_is_set(argparser_result, "i"))
	{
		shenv_singleton()->shvars = twl_lst_new();
	}
	t_lst *remainders_copy = twl_lst_copy(argparser_result->remainders, NULL);
	while (twl_lst_first(remainders_copy) && twl_strchr(twl_lst_first(remainders_copy), '='))
	{
		shenv_shvars_set_split_by_equal(shenv_singleton(), twl_lst_pop_front(remainders_copy), "env");
	}
	if (twl_lst_len(remainders_copy) == 0)
	{
		shenv_print(shenv_singleton());
	}
	else
	{
		char			*str_cmd = twl_lst_strjoin(argparser_result->remainders, " ");
		ast_exec_string(str_cmd);
	}
}

static void			exec_remaining_command_in_new_env(t_argparser_result *argparser_result)
{

	t_shenv 		*env_copy;
	t_shenv 		*env_src;

	env_src = shenv_singleton();
	env_copy = shenv_copy(env_src);
	shenv_singleton_setter(env_copy);
	exec_remaining_command(argparser_result);
	env_src->last_exit_code = env_copy->last_exit_code;
	shenv_singleton_setter(env_src);
	shenv_del(env_copy);
}

void				builtin_env_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_env_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		shenv->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		exec_remaining_command_in_new_env(argparser_result);
	}
}
