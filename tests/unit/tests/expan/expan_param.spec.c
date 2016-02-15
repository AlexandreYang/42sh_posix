#include <project.h>

#include "basics.h"
#include "expan/expan_mgr.h"
#include "expan/expan_param.h"
#include "expan/expan_exec.h"
#include "expan/expan_token_origin.h"
#include "environment.h"
#include "builtin/set.h"
#include "builtin/export.h"

static void simple_pos_param(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	set("set lol pouet", env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}


static void simple_pos_param_sub(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	export("set lol pouet", env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}

static void simple_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset LOL", env);
	export("export LOL=POUET", env);
	str = twl_strdup("$LOL");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	str = twl_strdup("${LOL}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	unset("unset LOL", env);
}

static void colon_hyphen_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset HAHA", env);
	str = twl_strdup("${HAHA:-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"ls") == 0);
	twl_strdel(&str);
	export("export HAHA=HOHO", env);
	str = twl_strdup("${HAHA:-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	unset("unset HAHA", env);
}

static void colon_hyphen_param_str_quoted(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset HAHA", env);
	str = twl_strdup("${HAHA:-l\"}\"s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	str = twl_strdup("${HAHA:-l\'}\'s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	str = twl_strdup("${HAHA:-l\\}s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	unset("unset HAHA", env);
}

static void hyphen_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset HAHA", env);
	export("export HAHA=HOHO", env);
	str = twl_strdup("${HAHA-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	unset("unset HAHA", env);
	str = twl_strdup("${HAHA-HOHO}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	export("export HAHA", env);
	str = twl_strdup("${HAHA-HOHO}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
}

static void colon_equal_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X:=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	str = twl_strdup("${X:=lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

static void equal_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	str = twl_strdup("${X=lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	unset("unset X", env);
	export("export X", env);
	str = twl_strdup("${X=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

static void colon_question_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X:?abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	export("export X=lol", env);
	str = twl_strdup("${X:?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

static void question_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X?abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	export("export X=lol", env);
	str = twl_strdup("${X?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	unset("unset X", env);
	export("export X", env);
	str = twl_strdup("${X?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

static void colon_plus_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X:+abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	export("export X=lol", env);
	str = twl_strdup("${X:+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	unset("unset X", env);
	export("export X", env);
	str = twl_strdup("${X:+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

static void plus_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	unset("unset X", env);
	str = twl_strdup("${X+abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	export("export X=lol", env);
	str = twl_strdup("${X+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	unset("unset X", env);
	export("export X", env);
	str = twl_strdup("${X+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	unset("unset X", env);
}

void	suite_expan_param(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_pos_param);
	SUITE_ADD_TEST(suite, simple_pos_param_sub);
	SUITE_ADD_TEST(suite, simple_param_str);
	SUITE_ADD_TEST(suite, colon_hyphen_param_str);
	SUITE_ADD_TEST(suite, colon_hyphen_param_str_quoted);
	SUITE_ADD_TEST(suite, hyphen_param_str);
	SUITE_ADD_TEST(suite, colon_equal_param_str);
	SUITE_ADD_TEST(suite, equal_param_str);
	SUITE_ADD_TEST(suite, colon_question_param_str);
	SUITE_ADD_TEST(suite, question_param_str);
	SUITE_ADD_TEST(suite, colon_plus_param_str);
	SUITE_ADD_TEST(suite, plus_param_str);
}
