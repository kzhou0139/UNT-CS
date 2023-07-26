//Static array: memory is allocated during compile time
//Dynamic array: memory is allocated during run time

#include <iostream>
using namespace std;

//const int SIZE=10;

int main()
{
	//int array[SIZE]; //static array
	
	int* array; //declare a pointer
	
	
	
	int num;
	cout<<"How many numbers?"; cin>>num;
	
	array=new int[num]; //allocation of dynamic memory
	
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
	}
	
	int sum=0;
	for (int i=0;i<num;++i)
	{
		sum+=array[i];
	}
	

	
	for (int i=0;i<num;++i)
	{
		cout<<array[i]<<endl;
	}
	
	cout<<"Sum="<<sum<<endl;
		
	delete [] array; //deallocation of memory	 
		
	return 0;
}