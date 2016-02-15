#include <project.h>

#include "environment.h"
#include "builtin/set.h"
#include "xopt.h"
#include <stdlib.h>

static void     set_flag(t_test *test)
{
    t_environment        *env;
    char                *flags;

    (void)test;
    env = environment_new();
	environment_init(env);
    set("set -x -a -b", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "xab") == 0);
	environment_del(env);
	free(flags);
}

static void test_unset_flag(t_test *test)
{
    t_environment        *env;
    char                *flags;

    (void)test;
	env = environment_new();
	environment_init(env);
    set("set -x -a -b", env);
    set("set +x", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "ab") == 0);
    free(flags);
    set("set +b", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "a") == 0);
    free(flags);
    set("set +a", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "") == 0);
    free(flags);
	environment_del(env);
}

static void test_wrong_flag(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set -a -b", env);
	mt_assert(twl_lst_len(env->flags) == 2);
	environment_del(env);
}

static void 	set_verbose(t_test *test)
{
	t_environment		*env;
	char				*flags;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set -o errexit", env);
	set("set -o nounset", env);
	set("set -o noexec lol", env);
	flags = environment_concat_flags(env);
	mt_assert(twl_strcmp(flags, "eun") == 0);
	environment_del(env);
	free(flags);
}

static void 	test_unset_verbose(t_test *test)
{
	t_environment		*env;
	char				*flags;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set -o errexit", env);
	set("set -o nounset", env);
	set("set -o noexec lol", env);
	set("set +o nounset", env);
	flags = environment_concat_flags(env);
	mt_assert(twl_strcmp(flags, "en") == 0);
	environment_del(env);
	free(flags);
}

static void 	set_pos_param(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set pouet lol", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	set("set hihi haha", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	environment_del(env);
}

static void 	set_hyphen(t_test *test)
{
	t_environment		*env;
	char				*flags;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set --", env);
	mt_assert(twl_lst_len(env->pos_params) == 0);
	set("set -e -- hihi haha", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	flags = environment_concat_flags(env);
	mt_assert(twl_strcmp(flags, "e") == 0);
	environment_del(env);
	free(flags);
}


void            suite_builtin_set(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, set_flag);
	SUITE_ADD_TEST(suite, test_unset_flag);
	SUITE_ADD_TEST(suite, test_wrong_flag);
	SUITE_ADD_TEST(suite, set_verbose);
	SUITE_ADD_TEST(suite, test_unset_verbose);
	SUITE_ADD_TEST(suite, set_pos_param);
	SUITE_ADD_TEST(suite, set_hyphen);
}
