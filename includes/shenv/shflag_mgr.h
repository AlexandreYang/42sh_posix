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

#ifndef SHFLAG_MGR_H
# define SHFLAG_MGR_H

# include "basics.h"
# include "shenv/shflag.h"

t_lst				*shflag_mgr_new(void);
void				shflag_mgr_del(t_lst *shflags);
void				shflag_mgr_add(t_lst *shflags, t_shflag *shflag);
void				shflag_mgr_remove(t_lst *shflags, t_shflag *shflag);
void				shflag_mgr_print(t_lst *shflags);

#endif
