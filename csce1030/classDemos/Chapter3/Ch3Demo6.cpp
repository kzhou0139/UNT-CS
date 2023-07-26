#include <iostream>
using namespace std;

int main()
{
	char letter;
	
	cout<<"Enter letter grade:"; cin>>letter;
	
	if (letter=='A' || letter =='a')
	{
		cout<<"Excellent grade."<<endl;
	}
	else if (letter=='B' || letter =='b')
	{
		cout<<"Good grade."<<endl;
	}
	else if (letter=='C' || letter =='c')
	{
		cout<<"Passing grade."<<endl;
	}
	else if (letter=='D' || letter =='d')
	{
		cout<<"Try again next time."<<endl;
	}
	else if (letter=='F' || letter =='f')
	{
		cout<<"Failing grade."<<endl;
	}
	else
	{
		cout<<"Invalid grade."<<endl;
		
	}
	
	
		
	return 0;
}