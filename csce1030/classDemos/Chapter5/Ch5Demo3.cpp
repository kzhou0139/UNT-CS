#include <iostream>
using namespace std;

int main()
{
	const int SIZE=5;
	
	/* don't do this
	int sz;
	sz=5;
	int score[sz]; //don't use  a variable for array declaration
	
	*/
	
	int score[SIZE];
	
	double sum=0;
	cout<<"Enter "<<SIZE<< " integers:"<<endl;
	for (int i=0; i<SIZE; ++i)
	{
		cout<<"Enter integer #"<<i+1<<":";
		cin>>score[i];
		sum+=score[i];
	}
	
	cout<<"Average="<<sum/SIZE<<endl;
	
	/*
	for (int i=0; i<SIZE; ++i)
	{
		cout<<"Enter integer #"<<i+1<<":";
		cin>>score[i];
	}
	
	
	for (int i=0; i<SIZE; ++i)
	{
		sum+=score[i];
	}
	
	
	
	*/
	
	
	
	return 0;
}