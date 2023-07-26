#include <iostream>
using namespace std;
int main()
{
	int grade;
	cout<<"Enter grade:";
	cin>>grade;
	/*
	if (grade > 100)
	{
		cout<<"Invalid grade."<<endl;
	}
	
	else if (grade < 0)
	{
		cout<<"Invalid grade."<<endl;
	}*/
	
	
	if (grade > 100 || grade < 0)
	{
		cout<<"Invalid grade."<<endl;
	}
	else if (grade >= 60)
	{
		cout<<"Passing grade."<<endl;
	}
	
	else
	{
		cout<<"Failing grade."<<endl;
	}
	
	
	return 0;
}