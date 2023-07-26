#include <iostream>
using namespace std;

int main()
{
	char letter;
	
	cout<<"Enter letter grade:"; cin>>letter;
	/*
	if (letter=='A')
	{
		cout<<"Excellent grade."<<endl;
	}
	else if (letter=='B')
	{
		cout<<"Good grade."<<endl;
	}
	else if (letter=='C')
	{
		cout<<"Passing grade."<<endl;
	}
	else if (letter=='D')
	{
		cout<<"Try again next time."<<endl;
	}
	else if (letter=='F')
	{
		cout<<"Failing grade."<<endl;
	}
	else
	{
		cout<<"Invalid grade."<<endl;
		
	}*/
	
	switch(letter)
	{
		/*case 'a':*/ //if you want the lowercase to work as well
		
		case 'A':
			cout<<"Excellent grade."<<endl;
			break;
		case 'B':
			cout<<"Good grade."<<endl;
			break;
		case 'C':
			cout<<"Passing grade."<<endl;
			break;
		case 'D':
			cout<<"Try again next time."<<endl;
			break;
		case 'F':
			cout<<"Failing grade."<<endl;
			break;
		default:
			cout<<"Invalid grade."<<endl;
			break;
	}
	
	
	
	
	
	return 0;
}