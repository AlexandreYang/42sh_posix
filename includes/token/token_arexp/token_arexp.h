/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2016/02/13 18:53:28 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_AREXP_H
# define TOKEN_AREXP_H

# include "basics.h"
# include "token/token_arexp/token_arepx_type.h"

typedef struct			s_token_arexp
{
	t_token_arexp_type	type;
	char				*text;
}						t_token_arexp;

t_token_arexp			*token_arexp_new(char *text);
void					token_arexp_del(t_token *this);

#endif
