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

#include "utils.h"
#include "shenv/shenv.h"
#include <errno.h>

void				utils_tcsetpgrp_for_tty(pid_t gid, int tty)
{
	if (shenv_singleton()->shenv_is_inside_job_control)
		return ;
	LOG_INFO("tcsetpgrp fileno: %d: gid; %d", tty, gid);
	if (tcsetpgrp(tty, gid) < 0)
	{
		if (shenv_is_interactive(shenv_singleton()))
		{
			LOG_WARN("tcsetpgrp: %s (tty=%d, gid=%d)",
			twl_strerror(errno), tty, gid);
		}
		else
		{
			LOG_ERROR("tcsetpgrp: %s (tty=%d, gid=%d)",
			twl_strerror(errno), tty, gid);
		}
	}
}
