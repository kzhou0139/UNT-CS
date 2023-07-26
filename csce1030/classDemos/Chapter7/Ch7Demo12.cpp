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
		
	string word;
	
	while(fin>>word)
	{
		cout<<word<<endl;
	}
	
	
	fin.close();
	return 0;
}
