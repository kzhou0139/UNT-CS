#include "stdio.h"
#include "stdlib.h"
const int SIZE=10;
int main()
{
	FILE *fptr;
	int num[SIZE];
	int i;
	int count;
	int sum;
	fptr=fopen("input.dat", "r");
	
	if (fptr==NULL)
	{
		printf("File error\n");
		exit(1);	
	}
	
	count=0;
	while(fscanf(fptr, "%d", &num[count])==1)
	{
		++count;
	}
	
	sum=0;
	for (i=0;i<count;++i)
	{
		printf("You read %d\n", num[i]);
		sum+=num[i];
	}
	printf("sum=%d\n", sum);
	fclose(fptr);
	
	
	return 0;
}