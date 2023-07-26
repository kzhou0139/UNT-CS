#include "stdio.h"
#include "stdlib.h"

int main()
{
	char fname[20];
	char lname[20];
	char gender;
	int age;
	double salary;
	
	FILE *fp;
	fp=fopen("data.dat", "r");
	
	if (fp==NULL)
	{
		printf ("File error\n");
		exit(1);
	}
	
	
	//fin>>fname>>lname>>gender>>age>>salary;
	
	while(fscanf(fp, "%s %s %c %d %lf", fname,lname,&gender, &age,&salary)!=-1)
	{
		printf("%s %s %c %d %lf\n", fname,lname,gender,age,salary);
	}
	
	
	
	fclose(fp);
	
	
	return 0;
}