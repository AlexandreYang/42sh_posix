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

#include "ast/nodes/ast_list_item.h"
#include "async/job_mgr.h"
#include <signal.h>

static void			ast_list_item_after_fork(t_ast_list_item *this, pid_t pid)
{
	char			*cmd_str;
	t_job			*job;

	cmd_str = token_mgr_strjoin(this->list_item_tokens, " ");
	job = job_new(pid, cmd_str, this->list_item_tokens);
	job_mgr_env_push(job);
	if (shenv_singleton()->is_interactive_shell)
		twl_printf("[%d] %d\n", job->job_id, job->pid);
	free(cmd_str);
}

static void			ast_list_item_exec_child(t_ast_list_item *this)
{
  if (shenv_singleton()->is_interactive_shell)
    {
      /* Put the process into the process group and give the process group
         the terminal, if appropriate.
         This has to be done both by the shell and in the individual
         child processes because of potential race conditions.  */
      // pid = getpid ();
      // if (pgid == 0) pgid = pid;
      // setpgid (pid, pgid);
      // if (foreground)
      //   tcsetpgrp (shell_terminal, pgid);

      /* Set the handling for job control signals back to the default.  */
      signal (SIGINT, SIG_DFL);
      signal (SIGQUIT, SIG_DFL);
      signal (SIGTSTP, SIG_DFL);
      signal (SIGTTIN, SIG_DFL);
      signal (SIGTTOU, SIG_DFL);
      signal (SIGCHLD, SIG_DFL);

      signal (SIGCONT, SIG_DFL);
    }
	ast_list_item_exec(this);
}

void				ast_list_item_exec_async(t_ast_list_item *this)
{
	pid_t			pid;

	pid = shenv_utils_fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_list_item_exec_child(this);
		exit(0);
	}
	else
	{
		ast_list_item_after_fork(this, pid);
	}
}
