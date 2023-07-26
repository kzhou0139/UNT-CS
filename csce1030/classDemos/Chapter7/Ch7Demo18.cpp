#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x=46, y=45;
	
	cout<<setw(20)<<x<<setw(45)<<y<<endl;
	
	double result=x/y;
	cout<<setw(15)<<setprecision(4)<<result<<endl;
	
	//cout<<3.0/7.0<<endl;
	
	
	
	return 0;
}