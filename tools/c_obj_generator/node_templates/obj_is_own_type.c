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

#include "ast/nodes/<OBJ_NAME>.h"

bool				<OBJ_NAME>_is_own_type(t_lst *tokens)
{
	t_token			*first_token;

	first_token = twl_lst_first(tokens);
	// if (first_token && twl_strequ(first_token->text, "\n"))
	// 	return (true);
	(void)tokens;
	(void)first_token;
	return (false);
}
