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

#ifndef TOKEN_MGR_H
# define TOKEN_MGR_H

# include "basics.h"
# include "token.h"

t_lst				*token_mgr_new(void);
void				token_mgr_del(t_lst *tokens);
void				token_mgr_add(t_lst *tokens, t_token *token);
void				token_mgr_remove(t_lst *tokens, t_token *token);
void				token_mgr_print(t_lst *tokens);

char				*token_mgr_strjoin(t_lst *tokens);

#endif
