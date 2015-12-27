#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

# define mt_test_token_mgr_extract_io_redirect(test_name, input, expected, remain, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*tokens; \
		char			*joined_str; \
		char			*remaining_str; \
		tokens = tokenizer_tokenize(input); \
		tokens_list = token_mgr_extract_io_redirect(tokens); \
		joined_str = token_mgr_split_strjoin(tokens_list); \
		remaining_str = token_mgr_strjoin(tokens); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual        {%s}\n", joined_str); \
			twl_printf("expected      {%s}\n", expected); \
			twl_printf("remaining_str {%s}\n", remaining_str); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		twl_lst_del(tokens, free); \
		twl_lst_del(tokens_list, NULL); \
	}

mt_test_token_mgr_extract_io_redirect(num1,
	"echo a > f1", ">_f1", "echo_a", false);

mt_test_token_mgr_extract_io_redirect(num2,
	"echo a > f1 > f2", ">_f1 / >_f2", "echo_a", false);

mt_test_token_mgr_extract_io_redirect(num3,
	"echo a <<- eof", "<<-_eof", "echo_a", false);

mt_test_token_mgr_extract_io_redirect(num4,
	"echo aa >> file1 < file2 < file3 bb cc", ">>_file1 / <_file2 / <_file3", "echo_aa_bb_cc", false);

mt_test_token_mgr_extract_io_redirect(num5,
	"echo aa > file1 bb > file2 cc > file3 dd", ">_file1 / >_file2 / >_file3", "echo_aa_bb_cc_dd", false);

void	suite_token_mgr_extract_io_redirect(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	// SUITE_ADD_TEST(suite, test_num4);
	// SUITE_ADD_TEST(suite, test_num5);
	// SUITE_ADD_TEST(suite, test_num6);
	// SUITE_ADD_TEST(suite, test_num7);
}
