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

#include "builtin/cmds/builtin_set.h"

static void			remove_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_shenv	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		shenv_remove_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		builtin_set_o_positive(env);
}

static void			add_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_shenv	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		shenv_add_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		builtin_set_o_negative(env);
}

void				builtin_set_exec(t_lst *tokens, t_shenv *env)
{
	t_set_opt		*opt;
	char			**arr;

	arr = token_mgr_to_str_arr(tokens);
	opt = builtin_set_opt_new(arr, SET_OPT_VALID_OPTS);
	if (!builtin_set_check_invalid_opts(opt, "set", SET_OPT_VALID_OPTS))
	{
		twl_lst_iter2(opt->positive_opts, remove_shell_flags, env, opt->args);
		twl_lst_iter2(opt->negative_opts, add_shell_flags, env, opt->args);
		if (twl_lst_len(opt->args) > 0)
			builtin_set_check_args(opt, env);
		else if (twl_lst_len(opt->positive_opts) == 0 && opt->negative_opts == 0)
		{
			shenv_print_all(env);
			shenv_last_exit_code_set(env, BUILTIN_EXEC_SUCCESS);
		}
	}
	builtin_set_opt_del(opt);
	twl_arr_del(arr, NULL);
}
