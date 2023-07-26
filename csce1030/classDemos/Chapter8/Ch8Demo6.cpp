#include <iostream>
using namespace std;
const int SIZE=30;
struct Student  //name of the structure: Student
{
	string name;
	double gpa;
};

void getData(Student st_array[], int& num)
{
	cout<<"How many students?";
	cin>>num;
	for (int i=0;i<num;++i)
	{
		cout<<"Enter data for student #"<<i+1<<":"<<endl;
		cin.ignore();
		cout<<"Enter name:"; getline(cin, st_array[i].name);
		cout<<"Enter GPA:"; cin>>st_array[i].gpa;
		
	}
}


void showData(Student st_array[], int num)
{
	for (int i=0;i<num;++i)
	{
		cout<<"Data for student #"<<i+1<<":"<<endl;
		cout<<"Name:"<<st_array[i].name<<"\tGPA:"<<st_array[i].gpa<<endl;
	}
	
}

int main()
{
	
	Student st_array[SIZE];
	int num;
	getData(st_array, num);
	showData(st_array, num);
	
	
	return 0;
}