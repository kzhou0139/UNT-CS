#include <iostream>
using namespace std;

bool compare (string str, int length)
{
	int str_length=str.length();
	bool isEqual=(str_length==length);
	return isEqual;	
	
	//return (str_length==length);
}


int main()
{
	string str="This is a test.";
	int length=105;
	bool isEqual=compare(str, length);	
	//bool isEqual=compare(length, str);	 //compilation error: arguments not in order
	if (isEqual)
	{		
		cout<<"It is of the same size."<<endl;	
	}
	else
	{
		cout<<"It is not of the same size."<<endl;
	}
	
	isEqual=compare("This is a string.", 25); //passing by value
	return 0;
	
}