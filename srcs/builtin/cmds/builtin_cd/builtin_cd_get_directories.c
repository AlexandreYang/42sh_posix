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

#include "builtin/cmds/builtin_cd.h"

static void			get_cdpath(t_lst *ret)
{
	char			*cdpath;
	char			**paths;
	size_t			index;

	if (!(cdpath = shenv_shvars_get_value(shenv_singleton(), "CDPATH")))
		return ;
	paths = twl_strsplit(cdpath, ':');
	index = 0;
	while (paths[index])
	{
		if (*paths[index])
			twl_lst_push_back(ret, paths[index]);
		else
			free(paths[index]);
		index += 1;
	}
	free(paths);
}

t_lst				*builtin_cd_get_directories(char *dir)
{
	char			*tmp;
	t_lst			*ret;

	ret = twl_lst_new();
	if (!dir)
	{
		tmp = shenv_shvars_get_value(shenv_singleton(), "HOME");
		if (!tmp)
		{
			shenv_singl_error(EXIT_FAILURE, "cd: HOME not set");
			return (ret);
		}
		twl_lst_push_back(ret, twl_strdup(tmp));
	}
	else if (dir[0] == '-' && dir[1] == '\0')
	{
		tmp = shenv_shvars_get_value(shenv_singleton(), "OLDPWD");
		if (!tmp)
		{
			shenv_singl_error(EXIT_FAILURE, "cd: OLDPWD not set");
			return (ret);
		}
		twl_lst_push_back(ret, twl_strdup(tmp));
	}
	else if (dir[0] == '/')
		twl_lst_push_back(ret, twl_strdup(dir));
	else if (dir[0] == '.' && dir[1] == '/')
		twl_lst_push_back(ret, twl_strdup(dir));
	else if (dir[0] == '.' && dir[1] == '.' && dir[2] == '/')
		twl_lst_push_back(ret, twl_strdup(dir));
	else
	{
		get_cdpath(ret);
		if (!twl_lst_len(ret))
			twl_lst_push_back(ret, twl_strdup(dir));
		else
			twl_lst_push_back(ret, twl_strdup("."));
	}
	return (ret);
}
