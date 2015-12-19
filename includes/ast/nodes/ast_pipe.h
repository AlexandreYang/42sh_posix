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

#ifndef AST_PIPE_H
# define AST_PIPE_H

# include "basics.h"

# include "parser.h"
# include "utils.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast_pipe
{
	t_ast_type		type;
	void			*left;
	void			*right;
	t_lst			*pipes;
	int				index;
}					t_ast_pipe;

t_ast_pipe			*ast_pipe_new(void);
void				ast_pipe_del(t_ast_pipe *this);

t_ast_pipe			*ast_pipe_build(char *str, int *len_ptr);
t_ast_pipe			*ast_pipe_build2(t_parser *parser);
void				ast_pipe_str_append(t_ast_pipe *this, t_lst *lines,
																int *depth);

#endif
