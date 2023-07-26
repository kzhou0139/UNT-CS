#include <iostream>
#include <fstream>
using namespace std;

struct Student  //name of the structure: Student
{
	string name;
	double gpa;
};

int main()
{
	ifstream fin;
	
	fin.open("data.dat");
	string fname, lname;
	double gpa;
	
	fin>>fname>>lname>>gpa;
	
	Student st8;
	cout<<"Data for Student #8:"<<endl;
	st8.name=fname+" "+lname;
	st8.gpa=gpa;
	
	cout<<"Name:"<<st8.name<<"\tGPA:"<<st8.gpa<<endl;
	
	fin.close();
		
	
	return 0;
}





