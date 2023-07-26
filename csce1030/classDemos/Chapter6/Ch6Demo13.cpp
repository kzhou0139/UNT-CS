#include <iostream>
using namespace std;
const int SIZE=5;

void getArray(int array[], int& num)
{
	cout<<"How any numbers you have?";
	cin>>num; //num must be <=SIZE
	cout<<"Enter "<<num<<" integers:";
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
	}
}

void showArray(int array[], int num)
{
	cout<<"The array is:"<<endl;
	for (int i=0;i<num;++i)
	{
		cout<<array[i]<<endl;
	}
}

int sumArray(int array[], int num)
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

	int array[SIZE];
	int num;
	
	/* moved to getArray
	cout<<"How any numbers you have?";
	
	cin>>num; //num must be <=SIZE
	cout<<"Enter "<<num<<" integers:";
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
	}
	*/
	getArray(array, num); //arrays are always passed by reference
	/* moved to sumArray
	int sum=0;
	for (int i=0;i<num;++i)
	{
		sum+=array[i];
	}
	*/
	int sum=sumArray(array, num);
	
	
	/*moved to showArray
	cout<<"The array is:"<<endl;
	for (int i=0;i<num;++i)
	{
		cout<<array[i]<<endl;
	}
	*/
	showArray(array, num);
	
	cout<<"Sum of the array="<<sum<<endl;
	
	
	return 0;
}