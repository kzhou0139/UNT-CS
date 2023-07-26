#include "stdio.h"
#include "stdlib.h"
int main()
{
	FILE *fptr;
	int my_int=25;
	float my_flt=2.65;
	double my_dbl=3.698;
	char my_char='&';
	char cstr[]="I will write this to the file.";
		
	fptr=fopen("myfile.txt", "w");
	
	if (fptr==NULL)
	{
		printf("File error\n");
		exit(1);	
	}
	
	fprintf(fptr, "Hello world!!!\n");
	fprintf(fptr, "my_int=%d\n", my_int);
	fprintf(fptr, "my_flt=%f\tmy_char=%c\n", my_flt, my_char);
	fprintf(fptr, "my_dbl=%lf\n", my_dbl);
	fprintf(fptr, "C-string=%s\n",cstr); 
	
	
	
	fclose(fptr);
	
	
	return 0;
}