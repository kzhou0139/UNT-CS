#include <iostream>
#include <fstream>
using namespace std;

//fin, fout: stream operators
int main()
{
	ifstream source;
	ofstream dest;
	source.open("text.txt");
	dest.open("copy.txt");
	
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