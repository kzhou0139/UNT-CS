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
	
	/*
	int num;
	int sum=0;
	for (int i=0; i<10 ;++i)
	{
		cout<<"Enter an integer:"; 
		cin>>num; //read from keyboard
		sum+=num;	
	}
	cout<<"Sum="<<sum<<endl;
	*/
	
	int num;
	int sum=0;
	for (int i=0; i<10 ;++i)
	{
		fin>>num; //read from file
		sum+=num;	
	}
	cout<<"Sum="<<sum<<endl;
	
	fin.close();
	return 0;
}






