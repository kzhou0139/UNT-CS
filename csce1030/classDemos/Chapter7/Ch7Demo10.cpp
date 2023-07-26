#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("text2.txt");
	
	char ch='#';
	
	//fout<<ch<<endl;
	
	//fout.put(ch);
	
	fout.put('Q');
	
	
	fout.close();
	
	return 0;
}