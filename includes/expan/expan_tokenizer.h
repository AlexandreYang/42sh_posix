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

#ifndef EXPAN_TOKENIZER_H
# define EXPAN_TOKENIZER_H

# include "basics.h"
# include "ast/ast.h"
# include "token/token.h"
# include "expan/expan_type.h"
# include "expan/expan_token.h"

typedef struct			s_expan_tokenizer
{
	t_token			*token;
	int				i;
	int				last;
	bool			is_between_dq;
	bool			is_between_sq;
	char			*str;
	t_lst			*expan_tokens;
	t_expan_type	type;
	t_token_origin	origin;
}						t_expan_tokenizer;

t_expan_tokenizer				*expan_tokenizer_new(t_token *token);
void							expan_tokenizer_del(t_expan_tokenizer *tokenizer);
void							expan_token_mgr_add(t_lst *tokens, t_expan_token *token);
void							expan_tokenizer(char *str, t_lst *expan_tokens,
	t_token_origin origin, t_token *token);
void							expan_tokenizer_none(t_expan_tokenizer *tokenizer, t_lst *expan_tokens,
	char *str, int len);
int								expan_tokenizer_param(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i);
int								expan_tokenizer_param_special(t_expan_token *expan_token,
	char *str, int i);
int								expan_tokenizer_tilde(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i);
int								expan_tokenizer_param_substitution(t_expan_token *expan_token,
		char *str, int i);
int								expan_tokenizer_command_dollar(t_expan_tokenizer *tokenizer,
			t_lst *expan_tokens, char *str,  int i);
int								expan_tokenizer_command_backquote(t_expan_tokenizer *tokenizer,
				t_lst *expan_tokens, char *str,  int i);
#endif
