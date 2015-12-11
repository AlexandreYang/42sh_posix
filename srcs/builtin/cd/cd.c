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

static void	get_flags(t_opt *opt, int *no_symlinks)
{
	if (twl_opt_exist(opt, "P"))
		*no_symlinks = 1;
	if (twl_opt_exist(opt, "L"))
		*no_symlinks = 0;
}

static char	*get_dirname_from_arg(t_opt *opt, t_environment *this)
{
	static char	buf[MAX_SIZE];
	char		*dirname;

	dirname = NULL;
	twl_bzero(buf, MAX_SIZE);
	dirname = twl_opt_args_get(opt, 0);
	if (!dirname || *dirname == '\0')
		return (NULL);
	if (dirname[0] != '/' && twl_strncmp(dirname, "..", 2) != 0)
		dirname = get_cdpath(dirname, this);
	return (dirname);
}

static int	get_dirname(char **dirname, t_opt *opt, char *str, t_environment *this)
{
	if (twl_opt_args_len(opt) == 0)
	{
		*dirname = environment_getenv_value(this, "HOME");
		if (*dirname == NULL || **dirname == '\0')
		{
			twl_dprintf(2, "%s: HOME not set\n", str);
			return (-1);
		}
		return (1);
	}
	else if (twl_strcmp(twl_opt_args_get(opt, 0), "-") == 0)
	{
		*dirname = environment_getenv_value(this, "OLDPWD");
		if (*dirname == NULL)
		{
			twl_dprintf(2, "%s: OLDPWD not set\n", str);
			return (-1);
		}
		return (1);
	}
	return (0);
}

void		cd_with_env(char *str, t_environment *this)
{
	int					no_symlinks;
	t_opt				*opt;
	char				**args;
	char				*dirname;

	if (!str || *str == '\0')
		return ;
	dirname = NULL;
	no_symlinks = 0;
	args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(args, "LP");
	if (!check_invalid_opts(opt, "cd", "LP"))
		return ;
	get_flags(opt, &no_symlinks);
	if (get_dirname(&dirname, opt, str, this) < 0)
		return ;
	else if (!dirname)
	{
		if (!(dirname = get_dirname_from_arg(opt, this)))
			return ;
	}
	if (dirname && dirname[0] != '/')
		dirname = join_pwd_to_path(dirname);
	execute_cd(dirname, no_symlinks, this);
}

void 		cd(char *str)
{
	t_environment *env;

	env = environment_singleton();
	cd_with_env(str, env);
}
