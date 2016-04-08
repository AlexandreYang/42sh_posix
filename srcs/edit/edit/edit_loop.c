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

#include "twl_stdlib.h"
#include "twl_xunistd.h"

#include "logger.h"
#include "edit/edit.h"
#include "edit/terminal.h"

#define DISABLE_FLAG(flag_storage, flag) (flag_storage &= ~(flag))
#define ENABLE_FLAG(flag_storage, flag) (flag_storage |= flag)


char				*edit_loop(t_edit *this)
{
	int				key;
	char			*cmd;
	char			*final_cmd;

	cmd = NULL;
	if (terminal_enable() == -1)
	{
		twl_xprintf("TERMINAL ERROR");
	}
	// TODO Error handling
	edit_print_letters(this);
	while (!this->return_cmd)
	{
		key = twl_getch();
		LOGGER_INFO("KEYPRESS: %d", key);
		cmd = edit_handle_one_input(this, key);
		edit_print_letters(this);
		edit_clear_line(this);
		edit_debug_print(this);
	}
	final_cmd = edit_match_valide_cmd(cmd);
	terminal_disable();
	return twl_strtrim_free(final_cmd);
}
