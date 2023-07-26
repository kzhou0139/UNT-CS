#include <iostream>
using namespace std;

const int NUMBER_OF_STUDENTS=4;
const int NUMBER_OF_TESTS=5;

struct Student
{
	string name;
	int tests[NUMBER_OF_TESTS];
	double average;
};

int main()
{
	Student st[NUMBER_OF_STUDENTS];
	
	
	for (int i=0;i<NUMBER_OF_STUDENTS;++i)
	{
		double sum=0;
		cout<<"Enter data for student #"<<i+1<<":";
		cout<<"Enter name:"; getline(cin, st[i].name);
		cout<<"Enter "<<NUMBER_OF_TESTS<<" scores:";
		for (int j=0;j<NUMBER_OF_TESTS;++j)
		{	
			cin>>st[i].tests[j];
			sum+=st[i].tests[j];
		}
		cin.ignore();
		st[i].average=sum/NUMBER_OF_TESTS;
		
	}
	
	
	for (int i=0;i<NUMBER_OF_STUDENTS;++i)
	{
		cout<<"Data for student #"<<i+1<<":";
		cout<<"Name:"<<st[i].name<<"\tScores:";
		for (int j=0;j<NUMBER_OF_TESTS;++j)
		{	
			cout<<st[i].tests[j]<<" ";
		}
		cout<<"Average:"<<st[i].average<<endl;
	}
	
	return 0;
}