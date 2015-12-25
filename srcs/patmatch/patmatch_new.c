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

#include "patmatch.h"

static char		*build_class_expr(int (*func)(int))
{
	char	expr[128];
	char	*ret;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < 128)
	{
		if (func(i))
		{
			expr[j] = i;
			j += 1;
		}
		i += 1;
	}
	expr[j] = 0;
	ret = twl_strdup(expr);
	return (ret);
}

static void		patmatch_build_class_expr_(t_patmatch *this)
{
	this->class_expr = twl_dict_new();
	twl_dict_add(this->class_expr, "[:alnum:]", build_class_expr(twl_isalnum));
	twl_dict_add(this->class_expr, "[:alpha:]", build_class_expr(twl_isalpha));
	twl_dict_add(this->class_expr, "[:blank:]", build_class_expr(twl_isblank));
	twl_dict_add(this->class_expr, "[:cntrl:]", build_class_expr(twl_iscntrl));
	twl_dict_add(this->class_expr, "[:digit:]", build_class_expr(twl_isdigit));
	twl_dict_add(this->class_expr, "[:graph:]", build_class_expr(twl_isgraph));
	twl_dict_add(this->class_expr, "[:lower:]", build_class_expr(twl_islower));
	twl_dict_add(this->class_expr, "[:print:]", build_class_expr(twl_isprint));
	twl_dict_add(this->class_expr, "[:punct:]", build_class_expr(twl_ispunct));
	twl_dict_add(this->class_expr, "[:space:]", build_class_expr(twl_isspace));
	twl_dict_add(this->class_expr, "[:upper:]", build_class_expr(twl_isupper));
	twl_dict_add(this->class_expr, "[:xdigit:]",
			build_class_expr(twl_isxdigit));
}

t_patmatch		*patmatch_new(void)
{
	t_patmatch		*this;

	this = twl_malloc_x0(sizeof(t_patmatch));
	patmatch_build_class_expr_(this);
	this->pattern = NULL;
	this->match = NULL;
	return (this);
}
