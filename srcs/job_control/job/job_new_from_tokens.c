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

#include "job_control/job.h"
#include "token/token_mgr.h"

t_job				*job_new_from_tokens(pid_t pid, t_lst *tokens)
{
	t_lst			*str_tokens;
	t_job			*job;

	str_tokens = token_mgr_to_lst(tokens);
	job = job_new(pid, str_tokens);
	twl_lst_del(str_tokens, NULL);
	return (job);
}
