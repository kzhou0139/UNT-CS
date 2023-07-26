#include <iostream>
using namespace std;

struct Student
{
	string name;
	long int id;
	double gpa;
};


struct Employee
{
	string name;
	int id;
	double salary;
};

int main()
{
	Student st;
	st.name="John Smith"; st.id=11110000; st.gpa=3.68;
	
	Employee emp;
	emp.name="Sheila Harris"; emp.id=5678; emp.salary=88978.25;
	
		
	
	
	return 0;
}