#include "stdio.h"
#include "stdlib.h"
int main()
{
	FILE *fptr;
	int num;
	fptr=fopen("input.dat", "r");
	
	if (fptr==NULL)
	{
		printf("File error\n");
		exit(1);	
	}
	
	fscanf(fptr, "%d", &num);
	printf("You read %d\n", num);
	
	
	fclose(fptr);
	
	
	return 0;
}