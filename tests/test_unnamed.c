/* test_unnamed.c test */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>

#include "test_unnamed_cmd.h"

static struct gengetopt_args_info args_info;

int main(int argc, char **argv)
{  
	if (test_unnamed_cmd_parser(argc, argv, &args_info) != 0) {
		exit(1);
	}

	test_unnamed_cmd_parser_free(&args_info);

	return 0;
}
