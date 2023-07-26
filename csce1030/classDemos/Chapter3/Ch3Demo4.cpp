#include <iostream>
using namespace std;

int main()
{
	int x=-10, y=25;
	char ch='*';
	
	
	if ((x>y) && (ch!='*'))
	{
		cout<<"This"<<endl;
	}
	else
	{
		cout<<"That"<<endl;
		
	}
	
	
	if ((x<y) || (ch!='*'))
	{
		cout<<"This, again"<<endl;
	}
	else
	{
		cout<<"That, again"<<endl;
		
	}
	
	
	if (!(x>y))
	{
		cout<<"This, again 2"<<endl;
	}
	else
	{
		cout<<"That, again 2"<<endl;
		
	}
	
	
	
	if (x<0 || y>50 || ch!='*')
	{
		cout<<"HELLO"<<endl;
	}
	else
	{
		cout<<"hello"<<endl;
		
	}
	
	
	if (x<0 && y>50 || ch!='*')
	{
		cout<<"HELLO, AGAIN"<<endl;
	}
	else
	{
		cout<<"hello, again"<<endl;
		
	}
	
	
	return 0;
}








