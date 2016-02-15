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

#include "builtin/eval.h"
#include "ast/ast.h"
#include "ast/nodes/ast_compound_list.h"

int					eval_builtin(char *cmd, t_environment *env)
{
	t_ast			*ast;
	int				ret;

	(void)env;
	ast = ast_new(&cmd[5]);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
		return (1);
	}
	ret = ast_exec(ast);
	ast_del(ast);
	return (ret);
}
