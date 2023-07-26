#include <iostream>
using namespace std;

int main()
{
	const int NUMBER_OF_STUDENTS=100;
	
	int scores[NUMBER_OF_STUDENTS];
	int num;
	cout<<"How many students are there in the class?"; 
	cin>>num; //cannot be greater than NUMBER_OF_STUDENTS
	
	for (int i=0;i<num;++i)
	{
		cout<<"Enter score for student #"<<i+1<<":";
		cin>>scores[i];
	}
	
	double sum=0;
	for (int i=0; i<num;++i)
	{
		sum+=scores[i];
	}
	
	cout<<"Average="<<sum/num<<endl;
	
	
	return 0;
}