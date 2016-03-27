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

#include "builtin/cmds/builtin_bg.h"
#include <sys/wait.h>

static void         put_in_bg(t_job *job)
{
    t_shenv         *env;
    bool            cont;

    cont = true;

    twl_dprintf(2, "!!! NOT FULLY IMPLEMENTED !!!\n");
    env = shenv_singleton();
    /* Put the job into the foreground.  */
    tcsetpgrp (env->jc_terminal, job->pid);
    /* Send the job a continue signal, if necessary.  */

    if (cont)
    {
        tcsetattr (env->jc_terminal, TCSADRAIN, &job->tmodes);
        if (kill (job->pid, SIGCONT) < 0)
            twl_dprintf (2, "kill (SIGCONT)");
    }
    /* Wait for it to report.  */
    // wait_for_job (j);
    int status;
    pid_t pid = waitpid (job->pid, &status, WUNTRACED);
    (void)pid;
    (void)status;

    /* Put the shell back in the foreground.  */
    tcsetpgrp (env->jc_terminal, env->jc_pgid);

    /* Restore the shell’s terminal modes.  */
    tcgetattr (env->jc_terminal, &job->tmodes);
    tcsetattr (env->jc_terminal, TCSADRAIN, &env->jc_tmodes);
}

void                builtin_bg_put_job_in_bg(t_job *job)
{
    job_mgr_remove(shenv_singleton()->jobs, job);
    put_in_bg(job);
}
