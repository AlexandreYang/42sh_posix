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

#include "cd.h"

void	get_flags(t_opt *opt, int *no_symlinks)
{
	if (twl_opt_exist(opt, "P"))
		*no_symlinks = 1;
	if (twl_opt_exist(opt, "L"))
		*no_symlinks = 0;
}

int		free_all(char *dirname, char **args, t_opt *opt)
{
	if (dirname)
		free(dirname);
	if (args)
		twl_arr_del(args, free);
	if (opt)
		twl_opt_del(opt);
	return (0);
}