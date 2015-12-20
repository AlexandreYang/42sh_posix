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

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "basics.h"

# include "token.h"

# define END_OF_INPUT 1

typedef struct		s_tokenizer
{
	t_lst			*tokens;
	char			*input;
	int				i;
	int				ti;
}					t_tokenizer;

t_tokenizer			*tokenizer_new(char *input);
void				tokenizer_del(t_tokenizer *this);

void				tokenizer_delimit(t_tokenizer *this);

int					tokenizer_apply_rule1(t_tokenizer *this);
void				tokenizer_apply_rule8(t_tokenizer *this);

#endif
