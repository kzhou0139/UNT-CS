//Static array: memory is allocated during compile time
//Dynamic array: memory is allocated during run time

#include <iostream>
using namespace std;

//const int SIZE=10;

void getArray(int array[], int num)
{
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
	}
	
}


void showArray(int array[], int num)
{
	for (int i=0;i<num;++i)
	{
		cout<<array[i]<<endl;
	}
	
}


int getSum(int array[], int num)
{
	int sum=0;
	for (int i=0;i<num;++i)
	{
		sum+=array[i];
	}
	return sum;
	
}

int main()
{
	//int array[SIZE]; //static array
	
	int* array; //declare a pointer
	
	int num;
	cout<<"How many numbers?"; cin>>num;
	
	array=new int[num]; //allocation of dynamic memory
	
	getArray(array, num);
	
	showArray(array, num);
		
	cout<<"Sum="<<getSum(array, num)<<endl;
		
	delete [] array; //deallocation of memory	 
		
	return 0;
}