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

#include "environment.h"
#include "env.h"
#include "utils.h"
#include "twl_arr.h"
#include "twl_arr2.h"
#include "twl_opt.h"

static void		add_env_var(void *data_, void *context_)
{
	t_environment	*context;
	char			*data;

	data = data_;
	context = context_;
	if (twl_strchr(data, '='))
		environment_setenv(context, data);
}

static void		push_to_arr(void *data, void *arr)
{
	t_environment_var	*var;
	char				*str;

	var = data;
	str = twl_strjoin(var->key, "=");
	str = twl_strjoinfree(str, var->value, 'l');
	twl_arr_push(arr, str);
}

static void		**env_lst_to_arr(t_lst *lst)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(lst));
	twl_lst_iter(lst, push_to_arr, arr);
	return (arr);
}

static void		get_utility(void *data_, void *context)
{
	t_env_args		*env;
	char			*data;

	data = data_;
	env = context;
	if (!twl_strchr(data, '=') && env->has_utility == 0)
	{
		env->utility = twl_strdup(data);
		env->has_utility = 1;
	}
}

void			env(char *str)
{
	t_environment		*clone;
	t_environment		*this;
	t_opt				*opt;
	t_env_args			env;

	env.env_arr = NULL;
	clone = NULL;
	env.utility = NULL;
	env.has_utility = 0;
	env.args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(env.args, "i");
	this = environment_singleton();
	clone = twl_lst_len(opt->opts) == 0 ? environment_clone(this)
		: environment_new();
	twl_lst_iter(opt->args, add_env_var, clone);
	twl_lst_iter(opt->args, get_utility, &env);
	env.env_arr = (char **)env_lst_to_arr(clone->env_vars);
	if (env.has_utility)
		exec_env(&env, this);
	else
	{
		environment_print_env(clone);
		environment_del(clone);
		twl_opt_del(opt);
	}
}
