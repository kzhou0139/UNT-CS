#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fp;
	char ch;
	fp=fopen("text.txt", "r");
	
	if (fp==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		printf("%c", ch);
		ch=fgetc(fp);
	}
	
	fclose(fp);
	
	return 0;
}