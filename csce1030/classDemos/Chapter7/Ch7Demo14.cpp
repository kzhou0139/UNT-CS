#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("text.txt");
	if(fin.fail()) 
	{
		cout<<"File error."<<endl;
		exit(1); 
	}
		
	string line;
	
	getline(fin, line, '*');
	cout<<line<<endl;
	
	
		
	fin.close();
	return 0;
}
