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

#include "token/tokenizer.h"
#include "token/token.h"

void				tokenizer_arexp_delimit(t_tokenizer *this)
{
	t_token			*token;

	if (*this->curtoken != '\0')
	{
		token = token_arexp(this->curtoken);
		twl_lst_push_back(this->tokens, token);
		this->curtoken[0] = '\0';
	}
}
