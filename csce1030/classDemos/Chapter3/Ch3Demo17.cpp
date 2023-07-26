#include <iostream>
using namespace std;

int main()
{
	char ch;
	cout<<"Enter character:"; cin>>ch;
	
	if (isalpha(ch))
	{
		cout<<"You entered an alphabet."<<endl;
		if (isupper(ch))
		{
			cout<<"You entered uppercase character."<<endl;
		}
	
		else if (islower(ch))
		{
			cout<<"You entered lowercase character."<<endl;
		}
	}
	
	else if (isdigit(ch))
	{
		cout<<"You entered a digit."<<endl;
	}
	
	else if (isspace(ch))
	{
		cout<<"You entered a whitespace."<<endl;
	}
	
	else
	{
		cout<<"You entered a special character."<<endl;
		
	}
	return 0;
}











