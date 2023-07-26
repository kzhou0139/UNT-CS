#include <iostream>
using namespace std;

int main()
{
	string str1="hello";
	string str2;
	/*cout<<"Enter string:"; cin>>str2;*/
	str2="hEllo";
	
	if (str1==str2)
	{
		cout<<"They are equal."<<endl;
	}
	else
	{
		cout<<"They are NOT equal."<<endl;
		if (str1>str2)
		{
			cout<<"str1 is bigger."<<endl;
		}
		else
		{
			cout<<"str2 is bigger."<<endl;
		}
	}
	
	
	
	return 0;
}