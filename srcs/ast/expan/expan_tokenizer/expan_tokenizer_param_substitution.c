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

#include "ast/expan/ast_expan_tokenizer.h"
#include "ast/expan/ast_expan_param.h"
#include "ast/expan/ast_expan_utils.h"


t_expan_param_type	expan_tokenizer_param_substitution_get_operator(char *str, int *j)
{
	char				*operator;
	t_expan_param_type	type;

	operator = twl_strndup(str, 2);
	type = string_2_to_expan_parameter_type(operator);
	if (type != UNDEFINED_PARAM)
	{
		*j = 2;
		return (type);
	}
	twl_strdel(&operator);
	operator = twl_strndup(str, 1);
	*j = 1;
	return (string_1_to_expan_parameter_type(operator));
}

static int	expan_tokenizer_param_substitution_get_parameter_word(t_expan_param *expan_param,
	char *str, int i)
{
	int					j;
	t_expan_param_type	type;
	int					word_start;
	int					op_len;

	j = i;
	word_start = i;
	op_len = 0;
	twl_printf("IN %d %s\n", i, &str[j]);
	while (str[j] != 0 && str[j] != '}')
	{
		type = expan_tokenizer_param_substitution_get_operator(&str[j], &op_len);
		twl_printf("FOUND TYPE %d\n", type);
		if (type != UNDEFINED_PARAM)
		{
			expan_param->parameter = twl_strndup(&str[i], j - i);
			expan_param->type = type;
			j += op_len;
			word_start = j;
		}
		else
			j++;
	}
	twl_printf("OUT %d %s\n", j, &str[j]);
	if (word_start == i)
		expan_param->parameter = twl_strndup(&str[i], j - i);
	else
		expan_param->word = twl_strndup(&str[word_start], j - word_start);
	if (str[j] == '}')
		j++;
	return (j);
}

int		expan_tokenizer_param_substitution(t_expan_token *expan_token,
	char *str, int i)
{
	t_expan_param *expan_param;

	expan_param = expan_param_new();
 	i = expan_tokenizer_param_substitution_get_parameter_word(expan_param, str, i);
	expan_token->exec_expan = expan_param_type_to_func_dict(expan_param->type);
	expan_token->expan_data = expan_param;
	return (i);
}
