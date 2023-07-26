#include <iostream>
using namespace std;

int main()
{
	string str;
	cout<<"Enter string:"; getline(cin, str);
	bool found=false;
	char ch;
	for (int i=0; i<str.length(); ++i)
	{
		ch=str.at(i);
		
		if (isupper(ch))
		{
			found=true;
			cout<<"Uppercase chracter found"<<endl;
			break;
		}	
	
	}
	if (!found)
	{
		cout<<"There are no uppercase characters."<<endl;
	}
	
	
	return 0;
}