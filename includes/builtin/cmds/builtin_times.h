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

#ifndef BUILTIN_TIMES_H
# define BUILTIN_TIMES_H

# include <sys/stat.h>
# include <sys/types.h>
# include "basics.h"
# include "builtin/builtin.h"
# include "twl_opt.h"
# include "twl_opt_elem.h"
# include "error.h"

void			builtin_times_exec(t_lst *tokens, t_shenv *env);

#endif
