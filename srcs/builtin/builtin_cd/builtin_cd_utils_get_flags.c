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

#include "builtin/builtin_cd.h"

void				builtin_cd_utils_get_flags(t_opt *opt, int *no_symlinks)
{
	if (twl_opt_exist(opt, "P"))
		*no_symlinks = 1;
	if (twl_opt_exist(opt, "L"))
		*no_symlinks = 0;
}
