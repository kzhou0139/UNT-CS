#include <iostream>
using namespace std;

int main()
{
	string str;
	cout<<"Enter string:"; getline(cin, str);
	int count_digit=0;
	int count_e=0;
	char ch;
	
	for (int i=0; i<str.length(); ++i)
	{
		ch=str.at(i);
		
		if (isdigit(ch))
		{
			++count_digit;
		}	
		
		if (toupper(ch)=='E')
		{
			++count_e;	
		}
	}
	cout<<"There are "<<count_digit<<" digits."<<endl;
	cout<<"There are "<<count_e<<" e's or E's."<<endl;
	
	
	return 0;
}