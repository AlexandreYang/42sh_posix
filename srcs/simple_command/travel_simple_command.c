#include "simple_command.h"

void travel_simple_command(void *ast_node,  void *cmd_)
{
	t_simple_command *cmd;

	cmd = cmd_;
	if (ast_node_get_type(ast_node) == AST_LIST)
	{
		t_ast_list		*ast_list = ast_node;
		twl_printf("%s\n", "Root Detected");
		twl_lst_iter(ast_list->items, travel_simple_command, cmd);
	}
	else if (ast_node_get_type(ast_node) == AST_CMD)
	{
		twl_printf("%s\n", "AST CMD Detected");
		travel_ast_cmd(cmd, ast_node);
	}
}
