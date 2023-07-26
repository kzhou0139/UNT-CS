#include <iostream>
using namespace std;

int main()
{
	double x=2.0, y=3.0;
	
	double result=x/y;
	cout<<"result="<<result<<endl;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout<<"result="<<result<<endl;
	
	cout.precision(4);	
	cout<<"another ratio="<<5.0/6.0<<endl;
	
		
	return 0;
}






