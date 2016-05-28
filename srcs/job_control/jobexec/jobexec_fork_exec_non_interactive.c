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

#include "job_control/jobexec.h"

static void			jobexec_fork_exec_non_interactive_do(t_jobexec *je)
{
	pid_t			pid;

	pid = shenv_utils_fork();
	LOG_INFO("jobexec_fork_exec_should_tcset(je): %d", jobexec_fork_exec_should_tcset(je));
	if (pid == 0)
	{
		LOG_INFO("fork non interactive: %d", getpid());
		LOG_INFO("fork level: %d", shenv_singleton()->shenv_fork_level);
		if (shenv_singleton()->shenv_fork_level == 0)
		{
			if (setpgid(0, 0) < 0)
				LOG_ERROR("setpgid: %s", strerror(errno));
		}
		if (jobexec_fork_exec_should_tcset(je))
		{
			if (tcsetpgrp(0, getpid()) < 0)
				LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		}
		shenv_singleton()->shenv_fork_level++;
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		if (jobexec_fork_exec_should_tcset(je))
		{
			if (tcsetpgrp(0, getpid()) < 0)
				LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		}
		jobexec_fork_exec_wait_fn(je, pid, NULL);
	}
}

void				jobexec_fork_exec_non_interactive(t_jobexec *je)
{
	jobexec_fork_exec_non_interactive_do(je);
}
