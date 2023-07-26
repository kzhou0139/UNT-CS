#include <iostream>
using namespace std;

int main()
{
	/*
	string str="This is a test.";
	cout<<str<<endl;
	
	char cstr[]="This is a test.";
	cout<<cstr<<endl;
	*/
	
	string str[5];
	for (int i=0;i<5;++i)
	{
		getline(cin, str[i]);
	}
	
	cout<<"You entered:"<<endl;
	for (int i=0;i<5;++i)
	{
		cout<<str[i]<<endl;
	}
	
	char mychar[10][20];
	
	return 0;
}