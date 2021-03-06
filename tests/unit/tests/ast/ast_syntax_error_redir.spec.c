#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "cat <\n", "SyntaxError 1 : Expect argument after '<'", false);
mt_test_ast_error(02, "cat > a < < b\n", "SyntaxError 1 : Expect argument after '<'", false);
mt_test_ast_error(03, ">\n", "SyntaxError 1 : Expect argument after '>'", false);
mt_test_ast_error(04, "cat << EOF\nabc\nEOF\n;", "SyntaxError 4 : Syntax error near ';' : Empty simple command", false);

void	suite_ast_syntax_error_redir(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
}
