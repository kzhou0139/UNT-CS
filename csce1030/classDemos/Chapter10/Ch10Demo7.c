#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fp;
	char ch='+';
	fp=fopen("write.txt", "w");
	
	if (fp==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	
	//fprintf(fp, "%c", ch);
	
	fputc(ch, fp);
	
	fclose(fp);
	
	return 0;
}