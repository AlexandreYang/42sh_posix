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

#include "prog.h"
#include "ast/ast.h"
#include "edit/edit.h"
#include "trap/trap.h"
#include "trap/trap_mgr.h"
#include "job_control/job_mgr.h"
#include <setjmp.h>

static void			prog_run_interactive_loop(t_prog *prog,
	char *(get_input_fn)(t_prog *prog))
{
	while (true)
	{
		prog_run_interactive_loop_sigtstp_wrapper(prog, get_input_fn);
		job_mgr_wait_update(shenv_singleton()->jobs);
	}
}

void				prog_run_interactive(t_prog *prog)
{
	prog_prepare_traps(prog);
	if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_GNL)
		prog_run_interactive_loop(prog, prog_line_edit_get_input_gnl);
	else
	{
		if (edit_singleton()->dumb)
			prog_run_interactive_loop(prog, prog_get_next_line);
		else
			prog_run_interactive_loop(prog, prog_line_edit_get_input);
	}
}
