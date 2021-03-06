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

#include <sys/wait.h>
#include "shenv/shenv.h"
#include "shsignal/shsignal.h"

static void			job_elsif_fn(int *res)
{
	if (WIFCONTINUED(*res))
	{
		LOG_INFO("WIFCONTINUED");
	}
	else if (WIFEXITED(*res))
	{
		LOG_INFO("WIFEXITED");
	}
	else if (WIFSIGNALED(*res))
	{
		LOG_INFO("WIFSIGNALED: %d", WTERMSIG(*res));
		handle_exec_signal(WTERMSIG(*res));
	}
	else if (WIFSTOPPED(*res))
	{
		LOG_INFO("WIFSTOPPED");
	}
	else if (WSTOPSIG(*res))
	{
		LOG_INFO("WSTOPSIG");
	}
	else
	{
		LOG_INFO("UNKNOWN");
	}
}

void				job_utils_waitpid(pid_t pid, int *res_ptr)
{
	int				res;
	pid_t			waitpid_ret;

	LOG_INFO("waitpid(%d) start", pid);
	waitpid_ret = waitpid(pid, &res, WUNTRACED);
	LOG_INFO("waitpid(%d) end ; waitpid ret: %d", pid, waitpid_ret);
	if (waitpid_ret == -1)
	{
		shenv_singl_error(1, "waitpid: %s", twl_strerror(errno));
		LOG_ERROR("waitpid error: pid: %d: %s", pid, twl_strerror(errno));
	}
	else if (waitpid_ret == pid)
	{
		if (WIFEXITED(res))
		{
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
			LOG_INFO("exit status: %d", shenv_singleton()->last_exit_code);
		}
		job_elsif_fn(&res);
	}
	if (res_ptr)
	{
		*res_ptr = res;
		LOG_INFO("res: %lx ; res_ptr: %lx", res, *res_ptr);
	}
}
