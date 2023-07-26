#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	string line;
	fin.open("data.dat");
	
	while(!fin.eof())
	{
		getline(fin, line);
		cout<<line<<endl;
	}
	
	fin.close();
		
	return 0;
	
}