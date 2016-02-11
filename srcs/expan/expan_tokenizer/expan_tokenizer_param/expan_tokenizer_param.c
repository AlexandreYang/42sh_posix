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

#include "expan/expan_tokenizer.h"
#include "expan/expan_param.h"
#include "expan/expan_utils.h"

int				expan_tokenizer_param(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i){
	t_expan_token	*expan_token;

	i++;
	expan_token = expan_token_new(PARAMETER);
	expan_token->origin = tokenizer->origin;
	expan_token->free_expan = expan_param_del;
	if (str[i] == '{')
		i = expan_tokenizer_param_substitution(expan_token, str, ++i);
	else
		i = expan_tokenizer_param_special(expan_token, str, i);
	expan_token->is_double_quoted = tokenizer->is_between_dq;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (i);
}