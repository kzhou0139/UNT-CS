#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream source;
	ofstream dest;
	source.open(argv[1]);
	dest.open(argv[2]);
	
	if (source.fail() || dest.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	char ch;
	ch=source.get();
	while(!source.eof())
	{
		dest.put(ch);
		ch=source.get();
	}

	
	source.close();
	dest.close();
	
	
	return 0;
}