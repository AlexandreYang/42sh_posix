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

void				tokenizer_del(t_tokenizer *this)
{
	free(this->input);
	free(this->curtoken);
	free(this->curtokenplus);
	twl_lst_del(this->open_heredoc_tokens, NULL);
	twl_lst_del(this->tok_open_stack, free);
	free(this->err_msg);
	free(this);
}
