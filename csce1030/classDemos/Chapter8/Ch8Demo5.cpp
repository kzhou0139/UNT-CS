#include <iostream>
using namespace std;
const int SIZE=3;
struct Student  //name of the structure: Student
{
	string name;
	double gpa;
};

void getData(Student st_array[])
{
	for (int i=0;i<SIZE;++i)
	{
		cout<<"Enter data for student #"<<i+1<<":"<<endl;
		cout<<"Enter name:"; getline(cin, st_array[i].name);
		cout<<"Enter GPA:"; cin>>st_array[i].gpa;
		cin.ignore();
	}
}


void showData(Student st_array[])
{
	for (int i=0;i<SIZE;++i)
	{
		cout<<"Data for student #"<<i+1<<":"<<endl;
		cout<<"Name:"<<st_array[i].name<<"\tGPA:"<<st_array[i].gpa<<endl;
	}
	
}

int main()
{
	
	Student st_array[SIZE];
	
	getData(st_array);
	showData(st_array);
	
	
	
	return 0;
}