/*C++ headers
#include <iostream>
using namespace std;
*/

#include "stdio.h"
#include "stdlib.h"

int main()
{
	/* C++ method
	int* array; //declare a pointer
	int num;
	cout<<"How many numbers?"; 
	cin>>num;
	
	array=new int[num]; //allocation of dynamic memory

	cout<<"Enter "<<num<<" numbers:";
	int sum=0;
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
		sum+=array[i];
	}
		
	cout<<"Sum="<<sum<<endl;
		
	delete [] array; //deallocation of memory	 
	
	*/
	
	//C-method
	int* array; //declare a pointer
	int num;
	int sum=0;
	int i;
	
	printf("How many numbers?"); 
	scanf("%d",&num);
	
	//array=new int[num]; //allocation of dynamic memory
	//array=(int*)malloc(sizeof(int)*num);
	
	array=(int*)calloc(num, sizeof(int));

	printf("Enter %d numbers:", num);
	
	for (i=0;i<num;++i)
	{
		scanf("%d", &array[i]); //scanf("%d", array+i);
		sum+=array[i];
	}
		
	printf("Sum=%d\n",sum);
		
	//delete [] array; //deallocation of memory	
	free(array);
		
	return 0;
}