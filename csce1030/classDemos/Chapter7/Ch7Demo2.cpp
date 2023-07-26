#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	//fout.open("output2.txt"); //this will overwrite
	
	
	fout.open("output2.txt", ios::app); //this will append
	
	if(fout.fail()) //true if error in opening
	{
		cout<<"File error."<<endl;
		exit(1); //terminates the program
	}
	
	fout<<"Hello again, again, world!!!"<<endl;
	
	fout.close();
	
	return 0;
}