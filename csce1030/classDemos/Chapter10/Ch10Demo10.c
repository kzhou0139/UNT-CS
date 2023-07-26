#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fp;
	char line[100];
	fp=fopen("text.txt", "r");
	
	if (fp==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	while(fgets(line, 99, fp)!=NULL)
	{
		printf("%s", line);
	}
	
	fclose(fp);
	
	return 0;
}