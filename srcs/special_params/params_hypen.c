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

#include "basics.h"
#include "prog.h"
#include "environment.h"
#include "twl_lst.h"

char				*params_hyphen(void)
{
	t_environment	*env;

	env = environment_singleton();
	return (twl_itoa(env->info.cur_shell_pid));
}

char				*test_params_hyphen(t_environment *env)
{
	return (twl_itoa(env->info.cur_shell_pid));
}