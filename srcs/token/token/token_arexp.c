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

#include "token/token.h"

t_token				*token_arexp(char *text)
{
	t_token		*this;

	this = twl_malloc_x0(sizeof(t_token));
	this->type = token_arexp_type_from_str(text);
	this->text = twl_strdup(text);
	this->line = 0;
	this->col = 0;
	this->heredoc_text = NULL;
	return (this);
}
