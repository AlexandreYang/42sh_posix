#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "&\n", "SyntaxError 1 : Syntax error near '&' : Empty simple command", false);
mt_test_ast_error(02, ";\n", "SyntaxError 1 : Syntax error near ';' : Empty simple command", false);
mt_test_ast_error(03, "; ;\n", "SyntaxError 1 : Syntax error near ';' : Empty simple command", false);
mt_test_ast_error(04, "echo abc; ;\n", "SyntaxError 1 : Syntax error near ';' : Empty simple command", false);
mt_test_ast_error(05, "echo abc; &\n", "SyntaxError 1 : Syntax error near '&' : Empty simple command", false);
mt_test_ast_error(06, ";;;", "SyntaxError 1 : Syntax error near ';;'", false);
mt_test_ast_error(07, "echo abc& ;", "SyntaxError 1 : Syntax error near ';' : Empty simple command", false);
mt_test_ast_error(08, ";;", "SyntaxError 1 : Syntax error near ';;'", false);

void	suite_ast_syntax_error_list(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
	SUITE_ADD_TEST(suite, test_07);
	SUITE_ADD_TEST(suite, test_08);
}
