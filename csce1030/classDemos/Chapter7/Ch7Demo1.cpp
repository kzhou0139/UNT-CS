#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("output.txt");
	if(fout.fail()) //true if error in opening
	{
		cout<<"File error."<<endl;
		exit(1); //terminates the program
	}
	
	cout<<"Hello world!!!"<<endl; //writes to screen
	
	fout<<"Hello world!!!"<<endl; //writes to file
	
	fout.close();
	
	return 0;
}