#include <iostream>
using namespace std;
int main()
{
	string my_str; //string declaration
	
	my_str= "Hello friend"; //assignment
	
	cout<<"my_str="<<my_str<<endl;
	
	string my_str2= "This is CSCE 1030. Welcome to the class."; //initialization
	cout<<"my_str2="<<my_str2<<endl;
	
	my_str="Hello again"; //updating the string variable
	cout<<"my_str="<<my_str<<endl;
	
	string fname, lname;
	cout<<"Enter name:";
	cin>>fname>>lname;
	cout<<"Name is:"<<fname<<" "<<lname<<endl;
	
	string name;
	cout<<"Enter name:";
	//cin>>name; //only reads a single word
	getline(cin, name); //read more than one word
	
	cout<<"Name is:"<<name<<endl;
	
	
	return 0;
}