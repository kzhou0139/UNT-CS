#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");
	
	
	if(fin.fail()) //true if error in opening the file
	{
		cout<<"File error."<<endl;
		exit(1); //terminates the program
	}
	
	
	int num;
	/*
	cout<<"Enter an integer:"; 
	cin>>num; //read from keyboard
	cout<<"You entered:"<<num<<endl;
	*/
	
	
	fin>>num; //read from file
	cout<<"You read from file:"<<num<<endl;
	
	fin.close();
	return 0;
}