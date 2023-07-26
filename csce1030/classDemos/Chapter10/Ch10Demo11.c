#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fp, *fp2;
	char line[100];
	fp=fopen("text.txt", "r");
	fp2=fopen("copy2.txt", "w");
	
	if (fp==NULL || fp2==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	while(fgets(line, 99, fp)!=NULL)
	{
		//printf("%s", line);
		//fprintf(fp2, "%s", line);
		fputs(line, fp2);
	}
	
	fclose(fp);
	fclose(fp2);
	
	return 0;
}