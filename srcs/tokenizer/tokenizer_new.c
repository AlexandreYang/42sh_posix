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

#include "tokenizer.h"

t_tokenizer			*tokenizer_new(char *input)
{
	t_tokenizer		*this;

	this = twl_malloc_x0(sizeof(t_tokenizer));
	this->input = twl_strdup(input);
	this->curpos = input;
	this->curtoken = twl_strnew(twl_strlen(input));
	this->curtokenplus = twl_strnew(twl_strlen(input));
	this->cur_is_quoted = false;
	return (this);
}