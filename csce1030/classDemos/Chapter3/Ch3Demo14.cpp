#include <iostream>
using namespace std;

int main()
{
	string str="This is CSCE 1030.";
	
	//Accessing a character
	char ch;
	
	ch=str.at(0);
	cout<<ch<<endl; //First character
	
	cout<<str.at(1)<<endl;//Second character
	
	cout<<str.at(17)<<endl;//Last character

	//Lenght of the string
	int str_length=str.length(); //str.size()also works
	cout<<"Length of the string:"<<str_length<<endl;
	cout<<str.at(str_length-1)<<endl;//Last character
	
	//Appending strings
	string str1="Hello";
	string str2=" my friend!!!";
	cout<<"Before:"<<str1<<endl;
	str1.append(str2);
	cout<<"After:"<<str1<<endl;
	
	str1="Hello";
	cout<<"After append:"<<str1.append(" my FRIENDS!!!")<<endl;
	
	string str3="HELLO";
	string str4="my friend";
	string str5=str3+" "+str4;
	cout<<"After concat:"<<str5<<endl;
	
	return 0;
}









