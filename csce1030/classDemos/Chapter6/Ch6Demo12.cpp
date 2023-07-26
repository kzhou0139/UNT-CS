#include <iostream>
using namespace std;
const int SIZE=5;

void getArray(int array[])
{
	cout<<"Enter "<<SIZE<<" integers:";
	for (int i=0;i<SIZE;++i)
	{
		cin>>array[i];
	}
}

void showArray(int array[])
{
	cout<<"The array is:"<<endl;
	for (int i=0;i<SIZE;++i)
	{
		cout<<array[i]<<endl;
	}
}

int sumArray(int array[])
{
	int sum=0;
	for (int i=0;i<SIZE;++i)
	{
		sum+=array[i];
	}
	return sum;
}

int main()
{

	int array[SIZE];
	/* moved to getArray
	cout<<"Enter "<<SIZE<<" integers:";
	for (int i=0;i<SIZE;++i)
	{
		cin>>array[i];
	}
	*/
	getArray(array);
	/* moved to sumArray
	int sum=0;
	for (int i=0;i<SIZE;++i)
	{
		sum+=array[i];
	}
	*/
	int sum=sumArray(array);
	
	
	/*moved to showArray
	cout<<"The array is:"<<endl;
	for (int i=0;i<SIZE;++i)
	{
		cout<<array[i]<<endl;
	}
	*/
	showArray(array);
	
	cout<<"Sum of the array="<<sum<<endl;
	
	
	return 0;
}