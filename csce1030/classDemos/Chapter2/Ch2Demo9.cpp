#include <iostream>
using namespace std;

int main()
{
	
	short int my_short;
	my_short=25000;
	//my_short=55000; //integer overflow error
	cout<<"my_short="<<my_short<<endl;
	
	long long int my_int=100000000000;
	cout<<"my_int="<<my_int<<endl;
	
	unsigned short int my_ushort=55000;
	//unsigned short int my_ushort=-10; //don't store negative numbers
	cout<<"my_ushort="<<my_ushort<<endl;
	return 0;
}