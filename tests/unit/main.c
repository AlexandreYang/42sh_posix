#include <unistd.h>
#include <string.h>
#include <fw.h>
#include <mt.h>
#include <test.h>
#include <signal.h>
#include <locale.h>
#include "project.h"
#include "prog.h"
#include <mt_lst.h>

# define MT_ADD_PROTO(name)			void suite_ ## name(t_suite *suite)

PROTOTYPES

int main()
{
	t_mt	*mt = mt_create("libft");

	setbuf(stdout, NULL);

	ADD_TESTS

	prog_init(prog_singl(), (char *[]){"prog", "-A", NULL});
	int ret = mt_exec(mt);
	mt_del(mt);
	return(ret);
}
