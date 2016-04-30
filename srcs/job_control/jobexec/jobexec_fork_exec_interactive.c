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
#include "utils.h"

void				jobexec_fork_exec_interactive(t_jobexec *je)
{
	pid_t			pid;

	LOG_INFO("jobexec_fork_exec_interactive");
	pid = shenv_utils_fork();
	if (pid == 0)
	{
		if (setpgid(0, 0) < 0)
			LOG_ERROR("setpgid: %s", strerror(errno));
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		LOG_INFO("before wait_fn");
		jobexec_fork_exec_wait_fn(je, pid);
		LOG_INFO("after wait_fn");
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}
