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
	
	
	int num1, num2;
	
	/*
	cout<<"Enter two integers:"; 
	cin>>num1>>num2; //read from keyboard
	cout<<"You entered:"<<num1<<"\t"<<num2<<endl;
	*/
	
	
	fin>>num1>>num2; //read from keyboard
	cout<<"You read:"<<num1<<"\t"<<num2<<endl;
	
	fin.close();
	return 0;
}






