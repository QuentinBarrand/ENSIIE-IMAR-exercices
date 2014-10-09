#include <stdio.h>
#include <rpc/rpc.h>

#include "x2y.h"

void
client_convert(CLIENT* cl, float argument)
{

	float *nby, *nbx = &argument;

	// printf("Conversion de %f X\n", *nbx);

	if((nby = convert_x2y_3(nbx, cl)) == NULL)
	{
		clnt_perror(cl, "server");
		exit(2);
	}

	printf("%5.2e X font %5.2e Y.\r", *nbx, *nby);
	//printf("%5.2e X font %5.2e Y.\n", *nbx, *nby);
	fflush(stdout);
}

void
client_updateRate(CLIENT* cl, float argument)
{

}


int
main(int argc, char** argv)
{
	if(argc != 4)
	{
		printf("USAGE : %s <hostname> <operation> <value>\n", argv[0]);
		exit(1);
	}

	CLIENT* cl;
	char* server = argv[1];


	if((cl = clnt_create(server, finance, VERS, "tcp")) == NULL)
	{
		clnt_pcreateerror(server);
		exit(2);
	}


	int operation;
	float floatArgument;


	operation = atoi(argv[2]);
	floatArgument = atof(argv[3]);

	if(operation == 1)
	{
		client_updateRate(cl, floatArgument);
	}

	if(operation == 2)
	{
		while(1)
		{
			client_convert(cl, floatArgument);
			sleep(2);
		}
	}

}