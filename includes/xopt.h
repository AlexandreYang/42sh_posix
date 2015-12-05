/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:00:00 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XOPT_H
# define XOPT_H

# include "twl_opt.h"

# include "basics.h"

# define XOPT_VALID_OPTS "h"

typedef struct		s_xopt
{
	t_opt			*opt__;
	// bool			is_enabled;
}					t_xopt;

t_xopt				*xopt_new(void);
void				xopt_del(t_xopt *xopt);

t_xopt				*xopt_singleton(void);

void				xopt_init(t_xopt *xopt, char **av);
void				xopt_check_valid_opts(t_xopt *xopt);

#endif