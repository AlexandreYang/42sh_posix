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

void				utils_tcsetpgrp_for_tty_01(pid_t gid)
{
	int tty;

	if (shenv_singleton()->shenv_is_inside_job_control)
		return ;
	tty = isatty(0) ? 0 : 1;
	utils_tcsetpgrp_for_tty(gid, tty);
}
