//using pointer notation
#include <iostream>
using namespace std;

void getArray(int* array, int num)
{
	for (int i=0;i<num;++i)
	{
		cin>>*(array+i);  //array[i]= *(array+i)
	}
	
}

void showArray(int* array, int num)
{
	for (int i=0;i<num;++i)
	{
		cout<<*(array+i)<<endl;
	}
	
}

int getSum(int* array, int num)
{
	int sum=0;
	for (int i=0;i<num;++i)
	{
		sum+=*(array+i);
	}
	return sum;
	
}

int main()
{
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