//#: preprocesor directive
#include <iostream>
using namespace std;

//const double PI=3.1416;

#define PI 3.1416
/*
int add(int x, int y)
{
	return(x+y);
}*/

#define add(x,y) x+y

#define multiply(a,b,c) a*b*c

int main()
{
	double radius=3.0;
	double area=PI*radius*radius;
	cout<<"Area of circle="<<PI*radius*radius<<endl;
	
	cout<<"Sum="<<add(11,20)<<endl;
	cout<<"Product="<<multiply(2,3,4)<<endl;
	
	return 0;
}