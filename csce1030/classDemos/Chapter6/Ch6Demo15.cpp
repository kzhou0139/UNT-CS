#include <iostream>
using namespace std;
const int SIZE=50;

void getArray(int array[], int& num) //don't make array constant here
{
	cout<<"How any numbers you have?";
	cin>>num; 
	cout<<"Enter "<<num<<" integers:";
	for (int i=0;i<num;++i)
	{
		cin>>array[i];
	}
}

void showArray(const int array[], int num)
{
	cout<<"The array is:"<<endl;
	for (int i=0;i<num;++i)
	{
		cout<<array[i]<<endl;
	}
}

double average(int array[], int num) //won't compile, array must be constant
{
	double sum=0;
	for (int i=0;i<num;++i)
	{
		sum+=array[i];
	}
	return (sum/num);
	
}

int sumArray(const int array[], int num)
{
	int sum=0;
	//array[0]=5000; //does not compile, cannot modify constant
	for (int i=0;i<num;++i)
	{
		sum+=array[i];
	}
	cout<<"Average:"<<average(array, num)<<endl;
	return sum;
}

int main()
{

	int array[SIZE];
	int num;
	
	getArray(array, num); //arrays are always passed by reference
	
	int sum=sumArray(array, num);
	
	showArray(array, num);
	
	cout<<"Sum of the array="<<sum<<endl;
	
	
	return 0;
}