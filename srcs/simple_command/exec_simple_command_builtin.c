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

#include "simple_command.h"

static void	use_builtin(t_simple_command *cmd, char *builtin, char *string)
{
	void *func;
	void (*f)(char *str);

	func = twl_dict_get(cmd->builtin_func, builtin);
	if (func)
	{
		f = func;
		f(string);
	}
}

void  exec_simple_command_builtin(t_ast_cmd *ast_cmd, t_simple_command *cmd, char *builtin)
{
	char	*tmp;

	tmp = concatenate_ast_cmd(ast_cmd->strings);
	use_builtin(cmd, builtin, tmp);
	free(tmp);
}
