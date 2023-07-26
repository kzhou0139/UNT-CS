//array vs pointer
//pointer arithmetic

#include <iostream>
using namespace std;

int main()
{
	int array[5]={-5, 18, 6, 4, 12};
	
	int *ptr;
	
	ptr=array;
	
	cout<<"array="<<array<<endl; //output is an address
	
	cout<<"*array="<<*array<<endl; //output is -5
	//the name of the array is a pointer and it is pointing at the first element of the array
	
	cout<<"array[0]="<<array[0]<<endl;
	cout<<"&array[0]="<<&array[0]<<endl;
	
	
	
	cout<<"array+1="<<array+1<<endl; 
	cout<<"*(array+1)="<<*(array+1)<<endl;
	cout<<"array[1]="<<array[1]<<endl;
	cout<<"&array[1]="<<&array[1]<<endl;
	
	
	cout<<"array+2="<<array+2<<endl; 
	cout<<"*(array+2)="<<*(array+2)<<endl;
	cout<<"array[2]="<<array[2]<<endl;
	cout<<"&array[2]="<<&array[2]<<endl;
	
	//in general:  array[i]=*(array+i) and &array[i]=array+i; where i is an integer
	
	//*(array+3)  is not the same as *array+3
	
	
	return 0;
}