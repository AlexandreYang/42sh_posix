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
#include "twl_unistd.h"
#include "twl_arr.h"

#define VALID_OPTS ":c:eA"

static void			process_arg(t_prog *prog, char sign, char c, char *optarg)
{
	LOG_DEBUG("found:     %c%c", sign, c);
	if (optarg && c != '?')
	{
		LOG_DEBUG("           %s", optarg);
	}
	if (c == 'A')
		shenv_singleton()->shenv_flags = shenv_singleton()->shenv_flags | SHENV_FLAG_AST;
	else if (c == 'c' && optarg)
		prog->prog_command_arg = twl_strdup(optarg);
}

void				prog_parse_args(t_prog *prog, char **argv)
{
	char			getopt_c;
	(void)prog;
	(void)argv;
	g_twl_optsign_active = true;
	while ((getopt_c = twl_getopt(twl_arr_len(argv), argv, VALID_OPTS)) > 0)
	{
		if (getopt_c == '?')
		{
			LOG_DEBUG("not found: %c%c", g_twl_optsign, g_twl_optopt);
		}
		else
		{
			process_arg(prog, g_twl_optsign, getopt_c, g_twl_optarg);
		}
	}
	// exit(42);
	g_twl_optind = 0;
	g_twl_optpos = 0;
	g_twl_optsign_active = false;
}
