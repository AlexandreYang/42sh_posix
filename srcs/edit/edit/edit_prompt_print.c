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

#include "edit/edit.h"
#include "edit/prompt_info.h"
#include "expan/expansion.h"

static t_prompt_info	get_prompt_fn(char *ps)
{
	t_expansion			*expansion;
	t_prompt_info		prompt;

	expansion = expansion_new_from_text_prompt(ps);
	prompt = expansion_get_prompt_info(expansion);
	if (!prompt.prompt_expanded)
	{
		prompt.prompt_expanded = twl_strdup(ps);
		prompt.length = twl_strlen(ps);
	}
	expansion_del(expansion);
	return (prompt);
}

void					edit_prompt_print(t_edit *this)
{
	char				*ps;
	t_prompt_info		prompt;

	ps = (this->type == edit_type_ps1) ?
		shenv_shvars_get_value(shenv_singleton(), "PS1") :
		shenv_shvars_get_value(shenv_singleton(), "PS2");
	if (!ps)
		ps = "";
	prompt = get_prompt_fn(ps);
	this->puts(prompt.prompt_expanded);
	this->base_x = prompt.length % this->winsize_x;
	this->prompt_size = prompt.length;
	free(prompt.prompt_expanded);
}
