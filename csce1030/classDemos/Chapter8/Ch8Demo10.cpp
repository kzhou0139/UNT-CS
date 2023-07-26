#include <iostream>
using namespace std;

struct BirthDay
{
	int month;
	int day;
};

struct Student
{
	string name;
	long int id;
	double gpa;
	BirthDay bday;
};



struct Employee
{
	string name;
	int id;
	double salary;
	BirthDay bday;
};

int main()
{
	Student st;
	st.name="John Smith"; st.id=11110000; st.gpa=3.68;
	st.bday.month=01; st.bday.day=10;
	
	Employee emp;
	emp.name="Sheila Harris"; emp.id=5678; emp.salary=88978.25;
	emp.bday.month=6; emp.bday.day=25;
	
	cout<<"Student birthday:"<<st.bday.month<<"\t"<<st.bday.day<<endl;
	cout<<"Employee birthday:"<<emp.bday.month<<"\t"<<emp.bday.day<<endl;
	
	BirthDay bday;
	bday.month= 12; bday.day=25;
	
	
	return 0;
}

