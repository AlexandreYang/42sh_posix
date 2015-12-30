#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

# define mt_test_token_mgr_split_by_one_sep(test_name, input, sep, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_tokenize(input); \
		tokens_list = token_mgr_split_by_one_sep(tokens, sep); \
		joined_str = token_mgr_split_strjoin(tokens_list); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		twl_lst_del(tokens, free); \
		twl_lst_del(tokens_list, NULL); \
	}

mt_test_token_mgr_split_by_one_sep(num1, "echo 1;echo 2", ";",
									"echo_1_; / echo_2", false);

void	suite_token_mgr_split_by_one_sep(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	// SUITE_ADD_TEST(suite, test_num2);
	// SUITE_ADD_TEST(suite, test_num3);
	// SUITE_ADD_TEST(suite, test_num4);
	// SUITE_ADD_TEST(suite, test_num5);
	// SUITE_ADD_TEST(suite, test_num6);
	// SUITE_ADD_TEST(suite, test_num7);
	// SUITE_ADD_TEST(suite, test_num8);
}
