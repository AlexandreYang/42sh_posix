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
#include "expan/expan_exec.h"


char				*params_zero(void)
{
	t_shenv	*env;

	env = shenv_singleton();
	return (twl_strdup(env->info.name));
}

char				*test_params_zero(t_shenv *env)
{
	return (twl_strdup(env->info.name));
}


bool			expan_exec_param_zero(t_expan_token *expan_token)
{
	expan_token->res = params_zero();
	return (true);
}
