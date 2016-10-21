/* Copyright (c) 2007
 *   Minghui Jiang, James Anderson, Joel Gillespie, and Martin Mayne.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 * 3. The names of its contributors may not be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *	main.c - command-line interface of uShuffle
 *	Thu Feb 21 13:58:38 MST 2008
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "ushuffle.h"

void print_help_and_exit() {
	printf("uShuffle: a useful tool for shuffling biological sequences while preserving the k-let counts\n");
	printf("Options:\n"
			"  -s <string>     specifies the sequence\n"
			"  -n <number>     specifies the number of random sequences to generate\n"
			"  -k <number>     specifies the let size\n"
			"  -seed <number>  specifies the seed for random number generator\n"
			"  -b              benchmark\n");
	exit(0); 
}

int main(int argc, char **argv) {
	char *s = NULL, *t;
	int n = 1, k = 2, b = 0;
	struct rusage r1, r2;
	struct timeval t1, t2;
	struct timeval tv;
	double u1;
	unsigned long seed;
	int i, l;

	gettimeofday(&tv, NULL);
	seed = (unsigned long) tv.tv_sec;

	for (i = 1; i < argc; i++)
		if (!strcmp(argv[i], "-s")) {
			if (i + 1 < argc && argv[i + 1][0] != '-')
				s = argv[++i];
			else
				print_help_and_exit();
		} else if (!strcmp(argv[i], "-n")) {
			if (i + 1 < argc && argv[i + 1][0] != '-')
				n = atoi(argv[++i]);
			else
				print_help_and_exit();
		} else if (!strcmp(argv[i], "-k")) {
			if (i + 1 < argc && argv[i + 1][0] != '-')
				k = atoi(argv[++i]);
			else
				print_help_and_exit();
		} else if (!strcmp(argv[i], "-seed")) {
			if (i + 1 < argc && argv[i + 1][0] != '-')
				seed = atoi(argv[++i]);
			else
				print_help_and_exit();
		} else if (!strcmp(argv[i], "-b"))
			b = 1;
	if (n <= 0 || s == NULL)
		print_help_and_exit();

	l = strlen(s);
	if ((t = malloc(l + 1)) == NULL) {
		fprintf(stderr, "malloc failed\n");
		exit(1);
	}
	t[l] = '\0';
	srandom(seed);
	set_randfunc((randfunc_t) random);
	if (b)
		getrusage(RUSAGE_SELF, &r1);
	shuffle1(s, l, k);
	for (i = 0; i < n; i++) {
		shuffle2(t);
		if (!b)
			printf("%s\n", t);
	}
	if (b) {
		getrusage(RUSAGE_SELF, &r2);
		t1 = r1.ru_utime;
		t2 = r2.ru_utime;
		u1 = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) * 0.001;
		printf("%g\n", u1);				/* time in msec */
	}
	return 0;
}
