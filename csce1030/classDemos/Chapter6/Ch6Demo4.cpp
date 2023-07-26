#include <iostream>
using namespace std;

void compare (string str, int length)
{
	int str_length=str.length();
	if (str_length==length)
	{		
		cout<<"It is of the same size."<<endl;	
	}
	else
	{
		cout<<"It is not of the same size."<<endl;
	}
		
}


int main()
{
	string str="This is a test.";
	int length=15;
	compare(str, length);	
	return 0;
	
}