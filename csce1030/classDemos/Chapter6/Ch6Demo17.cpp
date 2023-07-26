#include <iostream>
using namespace std;

void func(int x=25, char ch='*', double d=10.2568)
{
	cout<<"x="<<x<<"\tch="<<ch<<"\td="<<d<<endl;
	
}

int main()
{
	int x=20;
	char ch='+';
	double d=2.65;
	cout<<"First call:";
	func(x,ch,d);
	
	cout<<"Second call:";
	func(x,ch);
	
	cout<<"Third call:";
	func(x);
	
	cout<<"Fourth call:";
	func();
	
	return 0;
}