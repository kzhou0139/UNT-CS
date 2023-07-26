#include "stdio.h"
#include "stdlib.h"

int main()
{
	//C-method
	int* array; //declare a pointer
	int num;
	int growth;
	int sum=0;
	int i;
	
	printf("How many numbers?"); 
	scanf("%d",&num);
	
	array=(int*)malloc(sizeof(int)*num);
	
	printf("Enter %d numbers:", num);
	
	for (i=0;i<num;++i)
	{
		scanf("%d", &array[i]); //scanf("%d", array+i);
		sum+=array[i];
	}
		
	printf("Old Sum=%d\n",sum);
	
	printf("How much growth?");  scanf("%d", &growth);
	
	array=realloc(array, sizeof(int)*(num+growth));
	
	printf("Enter %d numbers:", growth);
	for (i=num;i<num+growth;++i)
	{
		scanf("%d", &array[i]); //scanf("%d", array+i);
		sum+=array[i];
	}
	printf("New Sum=%d\n",sum);
	
	free(array);
		
	return 0;
}