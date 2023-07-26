//Introduction to structures

//struct: collection of variables


//an example of structures
/*
struct MyStructure //name of the structure: MyStructure
{
	int my_int; //member variables
	char ch;
	double my_dbl;
	string str;
	int array[50]; //member array
};
*/

#include <iostream>
using namespace std;

struct Student  //name of the structure: Student
{
	string name;
	double gpa;
};

int main()
{
	
	Student st; //st: structure variable/instance
	st.name="John Smith";
	st.gpa=3.6;
	cout<<"Data fot Student #1:"<<endl;
	cout<<"Name:"<<st.name<<"\tGPA:"<<st.gpa<<endl;
	
	Student st2;
	cout<<"Enter name:"; getline(cin, st2.name);
	cout<<"Enter GPA:"; cin>>st2.gpa;
	cout<<"Data for Student #2:"<<endl;
	cout<<"Name:"<<st2.name<<"\tGPA:"<<st2.gpa<<endl;
	
	return 0;
}





