#include <iostream>
using namespace std;

int main()
{
	//int -double are type compatible
	int my_int=12;
	int my_dbl;
	my_dbl=my_int;
	cout<<"my_dbl="<<my_dbl<<endl;
	
	double my_dbl2=3.654;
	int my_int2;
	my_int2=my_dbl2;
	cout<<"my_int2="<<my_int2<<endl;
	
	//int-char are type compatible
	
	char my_ch='+';
	int my_int3;
	my_int3=my_ch;
	
	cout<<"my_int3="<<my_int3<<endl;
	
	int my_int4=66;
	char my_ch2;
	my_ch2=my_int4;
	cout<<"my_ch2="<<my_ch2<<endl;
	
	//Implicit conversion -- compiler converts type of data if they are type compatible
	
	//Explicit conversion
	int x=2, y=3;
	
	//cout<<"ratio="<<25.0/10<<endl; //only works with numbers
	
	double result=static_cast<double>(x)/y; //explicit conversion
	cout<<"result="<<result<<endl;
	
	
	
	
	
	return 0;
}