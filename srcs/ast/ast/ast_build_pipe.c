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

#include "twl_xstring.h"

#include "ast/ast.h"
#include "ast/nodes/ast_pipe.h"

static void			build(t_ast_pipe *pipe, t_ast *ast)
{
	// twl_lst_push(pipe->pipes, ast_pipe_build2(parser));
	twl_lst_push(pipe->pipes, ast_pipe_new());
	while (parser_remain_len(ast->parser))
	{
		if (parser_is_pipe_elem(ast->parser) || parser_is_andor(ast->parser) || parser_cchar(ast->parser) == '\n')
			break ;
		ast->parser->index++;
	}
}

t_ast_pipe			*ast_build_pipe(t_ast *ast)
{
	t_ast_pipe		*pipe;

	pipe = ast_pipe_new();
	while (parser_remain_len(ast->parser))
	{
		build(pipe, ast);
		if (parser_is_pipe_elem(ast->parser))
			ast->parser->index += 2; // skip separator
		else
			break ;
	}
	(void)ast->parser;
	(void)build;
	return (pipe);
}
