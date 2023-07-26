#include "stdio.h"
#include "stdlib.h"
int main()
{
	FILE *fptr;
	int num;
	int i;
	fptr=fopen("input.dat", "r");
	
	if (fptr==NULL)
	{
		printf("File error\n");
		exit(1);	
	}
	
	
	while(fscanf(fptr, "%d", &num)==1)
	{
		printf("You read %d\n", num);
	}
	
	
	fclose(fptr);
	
	
	return 0;
}