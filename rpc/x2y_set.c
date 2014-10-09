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

	float *nby;
	
	if((nby = updaterate_3(&floatArgument, cl)) == NULL)
	{
		clnt_perror(cl, server);
		exit(2);
	}

	printf("Taux mis à jour à 1 X = %5.2e Y.\n", floatArgument, *nby);
}