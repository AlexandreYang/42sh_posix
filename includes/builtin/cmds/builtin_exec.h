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

#ifndef BUILTIN_EXEC_H
# define BUILTIN_EXEC_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "builtin/builtin.h"

void				builtin_exec_exec(t_lst *tokens, t_shenv *env);
void				builtin_exec_redir_handler(t_lst *redir_tokens_groups);
void				builtin_exec_redir_exec(int io_number,
		char *operator, char *param);
void				builtin_exec_exit(int exit_code);

t_argparser			*builtin_exec_argparser(void);

#endif
