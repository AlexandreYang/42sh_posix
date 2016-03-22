#include <project.h>

#include "shenv/shenv.h"
#include "expan/expan_exec.h"
#include "builtin/cmds/builtin_set.h"
#include "builtin/cmds/builtin_export.h"
#include "token/tokenizer.h"

static void simple_star(t_test *test)
{
	char			*ret;
	t_shenv	*env;


	env = shenv_new();
	shenv_init(env);
	builtin_export_exec(tokenizer_utils_tokenize("export IFS=["), env);
	builtin_set_exec(tokenizer_utils_tokenize("set lol pouet"), env);
	ret = test_params_star(env, false);
	mt_assert(twl_strcmp(ret,"lol pouet") == 0);
	free(ret);
	shenv_del(env);
}



void	suite_params_star(t_suite *suite)
{

	SUITE_ADD_TEST(suite, simple_star);
}
