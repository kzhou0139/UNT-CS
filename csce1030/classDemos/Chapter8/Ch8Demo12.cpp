#include <iostream>
#include <fstream>

using namespace std;
const int SIZE=10;

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
	Employee emp[SIZE];
	int count=0;
	double sum=0;
	while(fin>>emp[count].fname>>emp[count].lname>>emp[count].gender>>emp[count].age>>emp[count].salary)
	{
		
		++count;	
	}
	
	
	for (int i=0;i<count;++i)
	{
		sum+=emp[i].salary;	
	}
	cout<<"Average salary="<<sum/count<<endl;
	
	fin.close();
	
	
	return 0;
}