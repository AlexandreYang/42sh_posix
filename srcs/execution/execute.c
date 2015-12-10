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

#include "execute.h"

static int		execute2(char *path, char **args, char **env)
{
	int			pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		int i;
		i = execve(path, args, env);
		perror("env");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&pid);
		return (1);
	}
	return (0);
}

int				execute(char *path, char **args, char **env)
{
	struct stat	sb;

	if (!stat(path, &sb))
	{
		if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
			return (execute2(path, args, env));
		else
		{
			twl_dprintf(2, "env: %s: Permission denied\n", args[0]);
			return (-1);
		}
	}
	return (0);
}
