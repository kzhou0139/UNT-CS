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
		
	string line;
	
	while(!fin.eof())
	{
		getline(fin, line);
		cout<<line<<endl;
	}
	
	/*
	while(fin>>line)
	{
		cout<<line<<endl;
	}
	*/
	
	fin.close();
	return 0;
}
