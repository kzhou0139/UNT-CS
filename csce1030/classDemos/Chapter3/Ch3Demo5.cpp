#include <iostream>
using namespace std;

int main()
{
	//Boolean data type
	bool my_bool; //declaration
	my_bool=true; // or my_bool=false
	
	if (my_bool)
	{
		cout<<"HELLO"<<endl;
	}
	else
	{
		cout<<"hello"<<endl;
	}
	
	int x=-10, y=25;
	char ch='*';
	bool my_bool2=((x>y) && (ch!='*'));
	
	if (my_bool2)
	{
		cout<<"This"<<endl;
	}
	else
	{
		cout<<"That"<<endl;
		
	}
	
	//bool-int compatibility
	my_bool=true;
	int my_int;
	my_int=my_bool;
	cout<<"my_int="<<my_int<<endl;
	
	
	my_int=-12; //all non zero integer is true, 0 is false
	my_bool=my_int;
	//cout<<"my_bool="<<my_bool<<endl; //this does not display the word true or false
	
	if (my_bool)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	
	return 0;
}










