#include "stdio.h"
#include "stdlib.h"

int main()
{
	char fname[20];
	char lname[20];
	char gender;
	int age;
	double salary;
	char line[100];
	FILE *fp;
	fp=fopen("data.dat", "r");
	
	if (fp==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	
	
	while(fgets(line, 99, fp)!=NULL)
	{
		//printf("%s", line);
		sscanf(line,  "%s %s %c %d %lf", fname,lname,&gender, &age,&salary);
		printf("%s %s %c %d %lf\n", fname,lname,gender,age,salary);
	}
	
	//printf("\n");
	
	fclose(fp);
	
	
	return 0;
}