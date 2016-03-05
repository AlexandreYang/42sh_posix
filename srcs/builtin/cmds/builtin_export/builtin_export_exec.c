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

#include "builtin/cmds/builtin_export.h"

int					builtin_export_exec(t_lst *tokens, t_shenv *env)
{
	t_opt			*opt;
	char			**arr;

	arr = token_mgr_to_str_arr(tokens);
	opt = twl_opt_new(arr, EXPORT_OPT_VALID_OPTS);
	if (!builtin_utils_check_invalid_opts(opt, "export", EXPORT_OPT_VALID_OPTS))
	{
		if ((twl_opt_exist(opt, "p") && twl_opt_args_len(opt) == 0)
			|| twl_opt_args_len(opt) == 0)
		{
			builtin_export_verbose(env);
		}
		else
		{
			builtin_export_add(env, tokens);
		}
	}
	free(arr);
	twl_opt_del(opt);
	shenv_set_last_exit_status_2(env, BUILTIN_EXEC_SUCCESS);
	return (BUILTIN_EXEC_SUCCESS);
}
