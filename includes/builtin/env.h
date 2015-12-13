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

#ifndef ENV_H
# define ENV_H

# include <sys/stat.h>
# include <sys/types.h>

# include "builtin.h"
# include "environment.h"
# include "env.h"
# include "utils.h"
# include "twl_arr.h"
# include "twl_opt.h"
# include "execute.h"
# include "environment.h"
# include "twl_arr2.h"

# define ENV_OPT_VALID_OPTS "i"

typedef struct		s_env_args
{
	char				**args;
	char				**env_arr;
	char				*utility;
	int					utility_index;
	bool				has_utility;
	bool				was_executed;
}					t_env_args;

int					env(char *str);
void				exec_env(t_env_args *env, t_environment	*clone);
void				**env_lst_to_arr(t_lst *lst);
void				add_env_var(void *data_, void *context_);

#endif