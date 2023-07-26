#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fp, *fp2;
	char ch;
	fp=fopen("text.txt", "r");
	fp2=fopen("dest.txt", "w");
	
	if (fp==NULL || fp2==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		//printf("%c", ch);
		fputc(ch, fp2);
		ch=fgetc(fp);
	}
	
	fclose(fp);
	fclose(fp2);
	
	return 0;
}