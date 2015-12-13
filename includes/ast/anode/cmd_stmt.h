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

#ifndef CMD_STMT_H
# define CMD_STMT_H

# include "twl_lst.h"

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/anode/anode.h"

typedef struct		s_cmd_stmt
{
	t_atype			type;
	t_lst			*strings;
	t_lst			*redir_in;
	t_lst			*redir_out;
	t_lst			*redir_append;
	t_lst			*redir_heredoc;
}					t_cmd_stmt;

t_cmd_stmt			*cmd_stmt_new(void);
void				cmd_stmt_del(t_cmd_stmt *this);

t_cmd_stmt			*cmd_stmt_build(char *str, int *len_ptr);

void				cmd_stmt_append_str(t_cmd_stmt *this,
													int lvl, t_lst *out_list);

#endif