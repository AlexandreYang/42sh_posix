#include <project.h>

#include "environment.h"
#include "builtin/shift.h"
#include "xopt.h"
#include <stdlib.h>

static void 	test_simple_shift(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	set("set lol pouet", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	shift_builtin("shift", env);
	mt_assert(env->info.last_exit_status == BUILTIN_EXEC_SUCCESS);
	mt_assert(twl_lst_len(env->pos_params) == 1);
	// shift_builtin("shift", env);
	// mt_assert(env->info.last_exit_status == BUILTIN_EXEC_SUCCESS);
	// mt_assert(twl_lst_len(env->pos_params) == 0);
	environment_del(env);
}

// static void 	test_empty_params(t_test *test)
// {
// 	t_environment		*env;
//
// 	(void)test;
// 	env = environment_new();
// 	environment_init(env);
// 	shift_builtin("shift", env);
// 	mt_assert(env->info.last_exit_status == BUILTIN_EXEC_FAILURE);
// 	mt_assert(twl_lst_len(env->pos_params) == 0);
// 	shift_builtin("shift", env);
// 	mt_assert(env->info.last_exit_status == BUILTIN_EXEC_FAILURE);
// 	mt_assert(twl_lst_len(env->pos_params) == 0);
// 	environment_del(env);
// }

// static void 	test_shift_too_big(t_test *test)
// {
// 	t_environment		*env;
//
// 	(void)test;
// 	env = environment_new();
// 	environment_init(env);
// 	set("set lol pouet gnuk hihi", env);
// 	mt_assert(twl_lst_len(env->pos_params) == 4);
// 	shift_builtin("shift 6", env);
// 	mt_assert(env->info.last_exit_status == BUILTIN_EXEC_FAILURE);
// 	mt_assert(twl_lst_len(env->pos_params) == 0);
// 	environment_del(env);
// }


void            suite_shift(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, test_simple_shift);
	// SUITE_ADD_TEST(suite, test_empty_params);
	// SUITE_ADD_TEST(suite, test_shift_too_big);
}
