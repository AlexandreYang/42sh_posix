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

#include "edit/history.h"

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	char		*ctx_first;
	t_history	*this;

	this = ctx2;
	if (this->is_break)
		return ;
	ctx_first = twl_lst_pop_front(ctx1);
	if (!this->is_break && !ctx_first)
	{
		history_push(ctx2, line_new_from_string(data));
	}
	else if (!this->is_break && !twl_strcmp(ctx_first, data))
	{
		;
	}
	else
	{
		this->is_break = true;
	}
}

static bool		inner_loop_fn(t_history *this, t_lst *content,
		t_lst *copy, char *content_first)
{
	t_lst		*copy_copy;
	char		*copy_first;

	while ((copy_first = twl_lst_first(copy)))
	{
		if (twl_strcmp(copy_first, content_first))
		{
			twl_lst_pop_front(copy);
			continue ;
		}
		this->is_break = false;
		copy_copy = twl_lst_copy(copy, NULL);
		twl_lst_iter2(content, iter_fn, copy_copy, this);
		if (!twl_lst_first(copy_copy))
		{
			twl_lst_del(copy_copy, NULL);
			return (true);
			break ;
		}
		twl_lst_del(copy_copy, NULL);
		twl_lst_pop_front(copy);
	}
	return (false);
}

static void		find_and_slice(t_history *this, t_lst *content)
{
	t_lst		*copy;
	char		*content_first;
	bool		done;

	done = false;
	while (!done && (content_first = twl_lst_first(content)))
	{
		copy = twl_lst_copy(this->save, NULL);
		done = inner_loop_fn(this, content, copy, content_first);
		twl_lst_del(copy, NULL);
		free(twl_lst_pop_front(content));
	}
}

void			history_append_file_to_list(t_history *this, char *path)
{
	t_lst		*content;

	if (!(content = history_utils_get_histfile(path)))
		return ;
	find_and_slice(this, content);
	twl_lst_del(this->save, free);
	this->save = content;
}
