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

#include "twl_lst.h"
#include "data.h"

static void			push_data(t_lst *operators)
{
	twl_lst_push_front(operators, "*");
	twl_lst_push_front(operators, "/");
	twl_lst_push_front(operators, "%");
	twl_lst_push_front(operators, ">>");
	twl_lst_push_front(operators, "<<");
	twl_lst_push_front(operators, "=");
	twl_lst_push_front(operators, "&=");
	twl_lst_push_front(operators, "|=");
	twl_lst_push_front(operators, "^=");
	twl_lst_push_front(operators, "+=");
	twl_lst_push_front(operators, "-=");
	twl_lst_push_front(operators, "*=");
	twl_lst_push_front(operators, "/=");
	twl_lst_push_front(operators, "%=");
	twl_lst_push_front(operators, ">>=");
	twl_lst_push_front(operators, "<<=");
	twl_lst_push_front(operators, "~");
	twl_lst_push_front(operators, "!");
	twl_lst_push_front(operators, ">");
	twl_lst_push_front(operators, "<");
	twl_lst_push_front(operators, ">=");
	twl_lst_push_front(operators, "<=");
	twl_lst_push_front(operators, "==");
	twl_lst_push_front(operators, "!=");
}

t_lst				*data_all_arexp_operators(void)
{
	static t_lst	*operators = NULL;

	if (operators == NULL)
	{
		operators = twl_lst_new();
		twl_lst_push_front(operators, ",");
		twl_lst_push_front(operators, "(");
		twl_lst_push_front(operators, ")");
		twl_lst_push_front(operators, "?");
		twl_lst_push_front(operators, ":");
		twl_lst_push_front(operators, "||");
		twl_lst_push_front(operators, "&&");
		twl_lst_push_front(operators, "&");
		twl_lst_push_front(operators, "|");
		twl_lst_push_front(operators, "^");
		twl_lst_push_front(operators, "+");
		twl_lst_push_front(operators, "-");
		push_data(operators);
	}
	return (operators);
}
