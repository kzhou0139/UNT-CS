#include <iostream>
#include <fstream>

using namespace std;

struct Employee
{
	string fname;
	string lname;
	char gender;
	int age;
	double salary;
	
};


int main()
{
	
	ifstream fin;
	fin.open("data2.dat");
	Employee emp;
	int count=0;
	double sum=0;
	while(fin>>emp.fname>>emp.lname>>emp.gender>>emp.age>>emp.salary)
	{
		sum+=emp.salary;	
		++count;	
	}
	cout<<"Average salary="<<sum/count<<endl;
	
	fin.close();
	
	
	return 0;
}