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

#include "token/token_mgr.h"

void				token_mgr_pop_linebreak_colon_linebreak(t_lst *tokens)
{
	token_mgr_pop_linebreak(tokens);
	if (token_mgr_first_equ(tokens, ";"))
	{
		twl_lst_pop_front(tokens);
		token_mgr_pop_linebreak(tokens);
	}
}
