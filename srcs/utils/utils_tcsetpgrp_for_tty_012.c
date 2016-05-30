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
#include <errno.h>

void				utils_tcsetpgrp_for_tty_012(pid_t gid)
{
	int tty;

	tty = isatty(0) ? 0 : 1;
	LOG_INFO("tcsetpgrp fileno: %d", tty);
	if (tcsetpgrp(tty, gid) < 0)
	{
		LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}
