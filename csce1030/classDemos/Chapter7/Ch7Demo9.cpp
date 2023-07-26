#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("text.txt");
	if(fin.fail()) //true if error in opening the file
	{
		cout<<"File error."<<endl;
		exit(1); //terminates the program
	}
	
	/*
	char ch;
	cin>>ch;
	cout<<"You entered:"<<ch<<endl;
	*/
	
	char ch;
	/*
	while(fin>>ch)//this will not read whitespace
	{
		cout<<ch;
	}
	*/
	
	ch=fin.get(); 
	while(!fin.eof()) //true if file is over, false if file is not over
	{
		cout<<ch;
		ch=fin.get(); //it reads the whitespaces
	}
	
	
	
	fin.close();
	return 0;
}
