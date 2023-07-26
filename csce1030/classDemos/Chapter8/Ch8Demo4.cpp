#include <iostream>
using namespace std;
const int SIZE=5;
struct Student  //name of the structure: Student
{
	string name;
	double gpa;
};

int main()
{
	
	Student st_array[SIZE];
		
	st_array[0].name="John Smith";
	st_array[0].gpa=3.6;
	
	
	for (int i=1;i<SIZE;++i)
	{
		cout<<"Enter data for student #"<<i+1<<":"<<endl;
		cout<<"Enter name:"; getline(cin, st_array[i].name);
		cout<<"Enter GPA:"; cin>>st_array[i].gpa;
		cin.ignore();
	}
	
	for (int i=0;i<SIZE;++i)
	{
		cout<<"Data for student #"<<i+1<<":"<<endl;
		cout<<"Name:"<<st_array[i].name<<"\tGPA:"<<st_array[i].gpa<<endl;
	}
	
	return 0;
}