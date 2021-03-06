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

#include "builtin/cmds/builtin_wait.h"

static void			exec_job_str_id(t_job *job, char *str_token)
{
	if (!job)
	{
		shenv_singl_error(127, "wait: %s: no such job", str_token);
	}
	else
	{
		builtin_wait_put_job_in_wait(job);
	}
}

static void			iter_str_token_fn(void *str_token)
{
	t_job			*job;

	job = job_mgr_find_by_pid_perc_job_id(shenv_singleton()->jobs, str_token);
	exec_job_str_id(job, str_token);
}

void				builtin_wait_exec_segs(t_argparser_result *argparser_result)
{
	t_lst			*segs;

	segs = twl_lst_copy(argparser_result->remainders, NULL);
	if (twl_lst_len(segs) == 0)
		builtin_wait_exec_wait_all();
	twl_lst_iter0(segs, iter_str_token_fn);
	twl_lst_del(segs, NULL);
}
