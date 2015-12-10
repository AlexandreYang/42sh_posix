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
#include "twl_arr.h"
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_xstring.h"

static void		remove_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_environment	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		environment_remove_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		set_o_positive(env);
}

static void		add_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_environment	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		environment_add_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		set_o_negative(env);
}

void	set(char *str)
{
	t_set_opt		*opt;
	char			**arr;
	char			*error;
	t_environment	*env;

	env = environment_singleton();
	arr = twl_strsplit_mul(str, " \n\t");
	opt = set_opt_new(arr, SET_OPT_VALID_OPTS);
	if ((error = set_opt_check_invalid_opts(opt)))
		set_usage(error);
	else
	{
		twl_lst_iter2(opt->positive_opts, remove_shell_flags, env, opt->args);
		twl_lst_iter2(opt->negative_opts, add_shell_flags, env, opt->args);
		if (twl_lst_len(opt->args) > 0)
			set_check_args(opt, env);
	}
	set_opt_del(opt);
	twl_arr_del(arr, &free);
}

void	test_set(char *str, t_environment *env)
{
	t_set_opt		*opt;
	char			**arr;
	char			*error;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = set_opt_new(arr, SET_OPT_VALID_OPTS);
	if ((error = set_opt_check_invalid_opts(opt)))
		set_usage(error);
	else
	{
		twl_lst_iter2(opt->positive_opts, remove_shell_flags, env, opt->args);
		twl_lst_iter2(opt->negative_opts, add_shell_flags, env, opt->args);
		if (twl_lst_len(opt->args) > 0)
			set_check_args(opt, env);
	}
	set_opt_del(opt);
	twl_arr_del(arr, &free);
}
