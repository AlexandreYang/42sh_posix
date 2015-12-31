#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

# define mt_test_token_mgr_split(test_name, input, split_strings_str, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*split_strings; \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_tokenize(input); \
		split_strings = twl_str_split_to_lst(split_strings_str, "_"); \
		tokens_list = token_mgr_split(tokens, split_strings); \
		joined_str = token_mgr_split_strjoin(tokens_list); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		twl_lst_del(split_strings, free); \
		twl_lst_del(tokens, free); \
		twl_lst_del(tokens_list, NULL); \
	}

mt_test_token_mgr_split(num1, "echo 1;echo 2", ";",
									"echo_1_; / echo_2", false);
mt_test_token_mgr_split(num2, "echo 1 ; echo 2 ; echo 3", ";_&",
									"echo_1_; / echo_2_; / echo_3", false);
mt_test_token_mgr_split(num3, "echo 1&echo 2;echo 3", ";_&",
									"echo_1_& / echo_2_; / echo_3", false);
mt_test_token_mgr_split(num4, "cmd1;(cmd3;cmd4);cmd5", ";_&",
									"cmd1_; / (_cmd3_;_cmd4_)_; / cmd5", false);
mt_test_token_mgr_split(num5, "cmd1;(cmd3;(echo abc)cmd4);cmd5 & cmd6", ";_&",
									"cmd1_; / (_cmd3_;_(_echo_abc_)_cmd4_)_; / cmd5_& / cmd6", false);
mt_test_token_mgr_split(num6, "if abc; then 123; fi; echo hello & date", ";_&",
									"if_abc_;_then_123_;_fi_; / echo_hello_& / date", false);
mt_test_token_mgr_split(num7, "(echo abc; echo 123) & echo 777", ";_&",
									"(_echo_abc_;_echo_123_)_& / echo_777", false);
mt_test_token_mgr_split(num8, "echo 123 | echo abc", "|",
									"echo_123_| / echo_abc", false);
mt_test_token_mgr_split(num9, "; ; ; ;", ";", "; / ; / ; / ; / ", false);
mt_test_token_mgr_split(num10, "echo a|", "|", "echo_a_| / ", false);

mt_test_token_mgr_split(num101, "(abc", ";", "(_abc", false);
mt_test_token_mgr_split(num102, "(abc);(", ";", "(_abc_)_; / (", false);
mt_test_token_mgr_split(num103, "(aaa;bbb", ";", "(_aaa_;_bbb", false);
mt_test_token_mgr_split(num104, "(abc; ; ;", ";", "(_abc_;_;_;", false);

void	suite_token_mgr_split(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);

	SUITE_ADD_TEST(suite, test_num101);
	SUITE_ADD_TEST(suite, test_num102);
	SUITE_ADD_TEST(suite, test_num103);
	SUITE_ADD_TEST(suite, test_num104);
}