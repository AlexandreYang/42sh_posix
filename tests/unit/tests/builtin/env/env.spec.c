#include <project.h>

#include "env.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"

static void test_env(t_test *test)
{
	(void)test;
	env("env -i pouet=asdhashd /bin");
	// env("env -p pouet=asdhashd");
	// env("env -i pouet=asdasdasdads sadads=asdasd choucroute=bien");
	// env("env -i  cd");
}

void	suite_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_env);
}
