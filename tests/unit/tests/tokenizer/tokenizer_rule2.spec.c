#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "aa&&bb", 	            "aa && bb", true);
mt_test_tokenizer(num2, "aa&&&bb",     	        "aa && & bb", true);
mt_test_tokenizer(num3, "aa&&bb||cc<<-dd",     	"aa && bb || cc <<- dd", true);

void	suite_tokenizer_rule2(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
