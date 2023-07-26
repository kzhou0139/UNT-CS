
#include <iostream>
using namespace std;

struct Student  
{
	string name;
	double gpa;
};

void getData(Student& std)
{
	cout<<"Enter name:"; getline(cin, std.name);
	cout<<"Enter GPA:"; cin>>std.gpa;
}

void showData(Student std)
{
	cout<<"Name:"<<std.name<<"\tGPA:"<<std.gpa<<endl;
}

Student getData2()
{
	Student std;
	cout<<"Enter name:"; getline(cin, std.name);
	cout<<"Enter GPA:"; cin>>std.gpa;
	return std;
}

Student setData(string name, double gpa)
{
	Student std;
	std.name=name;
	std.gpa=gpa;
	return std;
}


int main()
{
	/*
	Student st3;
	getData(st3);
	cout<<"Data for Student #3:"<<endl;
	showData(st3);
	
	  
	Student st4=getData2();
	cout<<"Data for Student #4:"<<endl;
	showData(st4);*/
	
	Student st5=setData("First Last", 3.5);
	cout<<"Data for Student #5:"<<endl;
	showData(st5);
	
	Student st6={"ABCD ABCD", 3.9};
	cout<<"Data for Student #6:"<<endl;
	showData(st6);
	
	
	Student st7;
	
	st7.name="Test test";
	st7.gpa=(st5.gpa+st6.gpa)/2.0;
	cout<<"Data for Student #7:"<<endl;
	showData(st7);
	
	
	return 0;
}





