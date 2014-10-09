#include <stdio.h>
#include <rpc/rpc.h>

#include "x2y.h"


int
main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("USAGE : %s <value> <hostname>\n", argv[0]);
		exit(1);
	}

	CLIENT* cl;
	char* server = argv[2];


	if((cl = clnt_create(server, finance, VERS, "tcp")) == NULL)
	{
		clnt_pcreateerror(server);
		exit(2);
	}


	float floatArgument;
	floatArgument = atof(argv[1]);

	while(1)
	{
		float *nby;
		
		if((nby = convert_x2y_3(&floatArgument, cl)) == NULL)
		{
			clnt_perror(cl, server);
			exit(2);
		}

		printf("%5.2e X font %5.2e Y.\r", floatArgument, *nby);
		fflush(stdout);
		sleep(2);
	}

}