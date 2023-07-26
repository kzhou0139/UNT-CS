#include <iostream>
using namespace std;

int main()
{
	int x=2, y=3;
	
	double result=x/y;
	cout<<"result="<<result<<endl;
	
	x=10;
	result=x/y;
	cout<<"result="<<result<<endl;
	
	
	x=26;
	y=10;
	int quotient=x/y;
	cout<<"quotient="<<quotient<<endl;
	int remainder= x%y; // %: modulo operator, remainder operator
	cout<<"remainder="<<remainder<<endl;
	
	x=32;
	y=6;
	quotient=x/y;
	cout<<"quotient="<<quotient<<endl;
	remainder= x%y; // %: modulo operator, remainder operator
	cout<<"remainder="<<remainder<<endl;
	
	
	return 0;
}