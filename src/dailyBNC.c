/* dailyBNC.c - (C) 2014, Timo Buhrmester
 * dailyBNC - beat you to it!
 * See README for contact-, COPYING for license information. */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>

#include <libsrsirc/irc_basic.h>
#include <libsrsirc/irc_util.h>

#include <libsrsbsns/addr.h>

static void process_args(int *argc, char ***argv);
static void init(int *argc, char ***argv);
static void usage(FILE *str, const char *a0, int ec);


static void
process_args(int *argc, char ***argv)
{
	char *a0 = (*argv)[0];

	for(int ch; (ch = getopt(*argc, *argv, "h")) != -1;) {
		switch (ch) {
		case 'h':
			usage(stdout, a0, EXIT_SUCCESS);
			break;
		case '?':
		default:
			usage(stderr, a0, EXIT_FAILURE);
		}
	}

	*argc -= optind;
	*argv += optind;
}


static void
init(int *argc, char ***argv)
{
	process_args(argc, argv);
	if (*argc != 1)
		usage(stderr, (*argv)[0], EXIT_FAILURE);
}


static void
usage(FILE *str, const char *a0, int ec)
{
	#define I(STR) fputs(STR "\n", str)
	I("================================");
	I("== dailyBNC - beat you to it! ==");
	I("================================");
	fprintf(str, "usage: %s [-h] <server[:port]>\n", a0);
	I("");
	I("\t-h: Display brief usage statement and terminate");
	I("");
	I("(C) 2014, Timo Buhrmester (contact: #fstd on irc.freenode.org)");
	#undef I
	exit(ec);
}


int
main(int argc, char **argv)
{
	init(&argc, &argv);

	return EXIT_SUCCESS;
}
