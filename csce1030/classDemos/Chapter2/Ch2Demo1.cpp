#include <iostream>
using namespace std;

int main()
{
	//variable declaration
	float my_flt; //data type: float, name/identifier: my_flt
	int my_int;//data type: integer, name/identifier: my_int
	double my_dbl;
	char my_char;
	
	//assignment operations, = is called the assignment operator
	my_flt=2.7441;
	my_dbl=-9.65874;
	my_int=25;
	my_char='*';
	
	cout<<"my_flt:"<<my_flt<<endl;
	cout<<"my_dbl:"<<my_dbl<<"\tmy_int:"<<my_int<<endl;
	cout<<"my_char:"<<my_char<<endl;
	
	//int my_int; //cannot redeclare a variable
	
	//variable initialization
	int my_int2=25;
	double my_dbl2=3.698;
	
	cout<<"my_int2:"<<my_int2<<endl;
	
	my_int2=45; //updating the variable
	cout<<"my_int2:"<<my_int2<<endl;
	
	
	int my_int3;
	
	my_int3=my_int2;
	cout<<"my_int3:"<<my_int3<<endl;
	
	int my_int4=3*my_int+ 4*my_int2 + 50;
	cout<<"my_int4:"<<my_int4<<endl;
	
	my_int3=my_int3+5; //my_int3+=5;
	cout<<"my_int3:"<<my_int3<<endl;
	
	my_int3-=2;//my_int3=my_int3-2;
	cout<<"my_int3:"<<my_int3<<endl;
	
	//char ch=3.7895; //don't mismatch data types during assignment
	//double dbl='p';
	
	return 0;
}






