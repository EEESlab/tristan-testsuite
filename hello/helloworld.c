/*
 * TRISTAN TESTSUITE: HELLOWORLD
 *
 * Author: Nazareno Bruschi <nazareno.bruschi@unibo.it>
 *
 */

#include <stdio.h>
#include "pmsis.h"

int test_entry()
{
	printf("Hello, world!\n");
	return 0;
}

static void test_kickoff(void *arg)
{
    int ret = test_entry();
    pmsis_exit(ret);
}

int main()
{
    return pmsis_kickoff((void *)test_kickoff);
}

