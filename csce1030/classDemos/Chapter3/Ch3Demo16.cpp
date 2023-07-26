#include <iostream>
using namespace std;

int main()
{
	char ch='Q';
	char ch1=tolower(ch);
	
	cout<<ch1<<endl;
	
	ch1=toupper('r');
	cout<<ch1<<endl;
	
	string str="This is CSCE 1030. Welcome to the class!!!";
	str.at(5)=toupper(str.at(5));
	cout<<"Updated string:"<<str<<endl;
	
	return 0;
}