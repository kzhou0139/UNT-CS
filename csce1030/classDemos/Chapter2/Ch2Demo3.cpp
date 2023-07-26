#include <iostream>
using namespace std;

int main()
{
	double radius=3.5;
	const double PI=3.1416;
	//PI=10; //cannot update a constant
	double area=PI*radius*radius;
	cout<<"area of the circle="<<area<<endl;
	return 0;
}






