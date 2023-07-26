//swapping
#include <iostream>
using namespace std;

int main()
{
	
	int x=10, y=15;
	
	cout<<"before:x="<<x<<"\ty="<<y<<endl;
	//swap code
	int temp=x;
	x=y;
	y=temp;
	
	cout<<"after:x="<<x<<"\ty="<<y<<endl;
	
	
	
	return 0;
}