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

#include "builtin/builtin.h"

#include "data.h"

t_lst				*data_builtins(void)
{
	static t_lst *builtins;

	if (builtins == NULL)
	{
		builtins = twl_lst_new();
		twl_lst_push_back(builtins, builtin_new(".", builtin_dot_exec));
		twl_lst_push_back(builtins, builtin_new("alias", builtin_alias_exec));
		twl_lst_push_back(builtins, builtin_new("cd", builtin_cd_exec));
		twl_lst_push_back(builtins, builtin_new("echo", builtin_echo_exec));
		twl_lst_push_back(builtins, builtin_new("env", builtin_env_exec));
		twl_lst_push_back(builtins, builtin_new("eval", builtin_eval_exec));
		twl_lst_push_back(builtins, builtin_new("exit", builtin_exit_exec));
		twl_lst_push_back(builtins, builtin_new("export", builtin_export_exec));
		twl_lst_push_back(builtins, builtin_new("false", builtin_false_exec));
		twl_lst_push_back(builtins, builtin_new("jobs", builtin_jobs_exec));
		twl_lst_push_back(builtins, builtin_new("readonly", builtin_readonly_exec));
		twl_lst_push_back(builtins, builtin_new("set", builtin_set_exec));
		twl_lst_push_back(builtins, builtin_new("setenv", builtin_setenv_exec));
		twl_lst_push_back(builtins, builtin_new("shift", builtin_shift_exec));
		twl_lst_push_back(builtins, builtin_new("times", builtin_times_exec));
		twl_lst_push_back(builtins, builtin_new("true", builtin_true_exec));
		twl_lst_push_back(builtins, builtin_new("umask", builtin_umask_exec));
		twl_lst_push_back(builtins, builtin_new("unset", builtin_unset_exec));
		twl_lst_push_back(builtins, builtin_new("unsetenv", builtin_unsetenv_exec));
	}
	return (builtins);
}