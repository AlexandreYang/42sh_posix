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

#ifndef ANODE_H
# define ANODE_H

# include "basics.h"

# include "anode_type.h"

typedef struct		s_anode
{
	t_anode_type	type;
}					t_anode;

t_anode_type				anode_get_type(void *anode_);
char						*anode_to_string(void *anode_);

#endif
