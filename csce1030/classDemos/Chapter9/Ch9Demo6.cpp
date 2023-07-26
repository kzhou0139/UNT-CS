#include <iostream>
using namespace std;

struct Student
{
	string name;
	double gpa;
	
};

int main()
{
	Student* st_ptr;
	
	st_ptr=new Student;
	
	cout<<"Enter name:"; getline(cin, st_ptr->name);
	cout<<"Enter GPA:"; cin>>st_ptr->gpa;
	
	
	cout<<"Data for student #1:";
	cout<<"Name:"<<st_ptr->name<<"\tGPA:"<<st_ptr->gpa<<endl;
	
	delete st_ptr;
	
	return 0;
}