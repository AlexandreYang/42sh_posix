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

#include "cd.h"

static char	*get_dirname_from_arg(t_opt *opt, t_environment *this)
{
	static char	buf[MAX_SIZE];
	char		*dirname;
	char		*new_name;

	dirname = NULL;
	twl_bzero(buf, MAX_SIZE);
	dirname = twl_strdup(twl_opt_args_get(opt, 0));
	if (!dirname || *dirname == '\0')
		return (NULL);
	if (dirname[0] != '/' && twl_strncmp(dirname, "..", 2) != 0)
	{
		new_name = get_cdpath(dirname, this);
		free(dirname);
		return (new_name);
	}
	return (dirname);
}

static int	get_dirname(char **dirname, t_opt *opt, char *str,
	t_environment *this)
{
	if (twl_opt_args_len(opt) == 0)
	{
		*dirname = twl_strdup(environment_getenv_value(this, "HOME"));
		if (*dirname == NULL || **dirname == '\0')
		{
			twl_dprintf(2, "%s: HOME not set\n", str);
			return (-1);
		}
		return (1);
	}
	else if (twl_strcmp(twl_opt_args_get(opt, 0), "-") == 0)
	{
		*dirname = twl_strdup(environment_getenv_value(this, "OLDPWD"));
		if (*dirname == NULL)
		{
			twl_dprintf(2, "%s: OLDPWD not set\n", str);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int			cd_with_env(char *str, t_environment *this)
{
	int					no_symlinks;
	t_opt				*opt;
	char				**args;
	char				*dirname;

	dirname = NULL;
	no_symlinks = 0;
	args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(args, "LP");
	if (check_invalid_opts(opt, "cd", "LP"))
		return (free_all(dirname, args, opt));
	get_flags(opt, &no_symlinks);
	if (get_dirname(&dirname, opt, str, this) < 0)
		return (free_all(dirname, args, opt));
	else if (!dirname)
	{
		if (!(dirname = get_dirname_from_arg(opt, this)))
			return (free_all(dirname, args, opt));
	}
	if (dirname && dirname[0] != '/' && !no_symlinks)
		dirname = join_pwd_to_path(dirname);
	execute_cd(dirname, no_symlinks, this);
	return (free_all(dirname, args, opt));
}

void		cd(char *str)
{
	t_environment *env;

	env = environment_singleton();
	cd_with_env(str, env);
}