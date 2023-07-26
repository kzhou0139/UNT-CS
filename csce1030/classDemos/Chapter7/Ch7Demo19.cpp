#include <iostream>
#include <fstream>
using namespace std;

void my_copy(ifstream& source,ofstream& dest)
{
	char ch;
	ch=source.get();
	while(!source.eof())
	{
		dest.put(ch);
		ch=source.get();
	}
}

//alternatively, call from main: my_copy("text.txt", "copy.txt");
void my_copy2(string srcfile, string destfile)
{
	ifstream source;
	ofstream dest;
	source.open(srcfile);
	dest.open(destfile);
	
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
}

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

	/* moved to function
	char ch;
	ch=source.get();
	while(!source.eof())
	{
		dest.put(ch);
		ch=source.get();
	}
	*/
	my_copy(source, dest);
	source.close();
	dest.close();
	
	
	return 0;
}