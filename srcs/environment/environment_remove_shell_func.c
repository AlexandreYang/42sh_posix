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

#include "set.h"
#include "environment.h"
#include "twl_dict.h"
#include "twl_opt_elem.h"

static void			free_func(void *data)
{
	(void)data;
}

void				environment_remove_shell_func(t_environment *env, char *key)
{
	twl_dict_delone(env->shell_func, key, free_func);
}