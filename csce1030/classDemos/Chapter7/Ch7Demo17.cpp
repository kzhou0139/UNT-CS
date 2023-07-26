#include <iostream>
using namespace std;

int main()
{
	int x=20, y=30;
	cout.width(20);
	cout.setf(ios::left);
	cout<<x;
	
	cout.width(45);
	cout.setf(ios::right);
	cout<<y<<endl;
	
	
	return 0;
}