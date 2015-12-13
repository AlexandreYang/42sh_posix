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

#include "twl_xstdlib.h"

#include "environment.h"
#include "xopt.h"

t_environment			*environment_new(void)
{
	t_environment		*this;
	t_xopt				*xopt;

	this = twl_malloc_x0(sizeof(t_environment));
	this->env_vars = twl_lst_new();
	xopt = xopt_singleton();
	this->pos_params = xopt_get_args(xopt);
	this->flags = xopt_get_opts(xopt);
	return (this);
}