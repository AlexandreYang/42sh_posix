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

#ifndef EDIT_MOVE_H
# define EDIT_MOVE_H

# include "basics.h"
# include "edit/edit_key_func.h"

# define ARROW_LEFT 4479771
# define ARROW_RIGHT 4414235
# define ARROW_UP 4283163
# define ARROW_DOWN 4348699

# define DELETE_KEY 127
# define RETURN_KEY 10

# define CTRL_A 1
# define CTRL_D 4
# define CTRL_E 5
# define CTRL_C -1
# define CTRL_T 20
# define CTRL_U 21
# define CTRL_W 23
# define RETURN_KEY 10
# define CTRL_C -1
# define CTRL_T 20
# define CTRL_U 21
# define CTRL_W 23
# define CTRL_I 9
# define CTRL_P 16
# define CTRL_R 18

typedef void		(*key_fn)(void *edit);

typedef struct		s_edit_key
{
	int				key;
	key_fn			func;
}					t_edit_key;

t_edit_key			*edit_key_new(int key, key_fn fn);
void				edit_key_del(t_edit_key *this);

#endif
