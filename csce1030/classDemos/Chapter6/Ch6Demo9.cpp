//Passing by reference
#include <iostream>
using namespace std;


void change(char ch, int& my_int)
{
	ch='*'; my_int=30;
}

int main()
{
	char ch='q'; 
	int my_int=5;
	
	change(ch, my_int);
	
	cout<<"ch="<<ch<<"\tmy_int="<<my_int<<endl;
	
	return 0;
	
}