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
	
	int num;
	cout<<"How many students?"; cin>>num;
	
	st_ptr=new Student[num];
	
	for (int i=0;i<num ;++i)
	{
		cout<<"Enter data for student #"<<i+1<<":"<<endl;
		cin.ignore();
		cout<<"Enter name:"; getline(cin, st_ptr[i].name);
		cout<<"Enter GPA:"; cin>>st_ptr[i].gpa;
	}
	
	for (int i=0;i<num;++i)
	{
		cout<<"Data for student #"<<i+1<<":"<<endl;
		cout<<"Name:"<<st_ptr[i].name<<"\tGPA:"<<st_ptr[i].gpa<<endl;
	}
	
	delete [] st_ptr;
	
	return 0;
}