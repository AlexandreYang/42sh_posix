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

#include "token/token.h"

t_token				*token_copy(t_token *src)
{
	t_token		*this;

	this = twl_malloc_x0(sizeof(t_token));
	this->type = src->type;
	if (src->text)
		this->text = twl_strdup(src->text);
	this->line = src->line;
	this->col = src->col;
	if (src->heredoc_text)
		this->heredoc_text = twl_strdup(src->heredoc_text);
	return (this);
}
