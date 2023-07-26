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
	int num[10];
	int sum=0;
	for (int i=0; i<10 ;++i)
	{
		cout<<"Enter an integer:"; 
		cin>>num[i]; //read from keyboard
		
	}
	
	for (int i=0;i<10;++i)
	{
		sum+=num[i];
	}
	
	cout<<"You entered:";
	for (int i=0;i<10;++i)
	{
		cout<<num[i]<<endl;
	}
	cout<<"Sum="<<sum<<endl;
	*/
	
	
	int num[10];
	int sum=0;
	for (int i=0; i<10 ;++i)
	{
		fin>>num[i]; //read from file
		
	}
	
	for (int i=0;i<10;++i)
	{
		sum+=num[i];
	}
	
	cout<<"You read:";
	for (int i=0;i<10;++i)
	{
		cout<<num[i]<<endl;
	}
	cout<<"Sum="<<sum<<endl;
	
	
	
	fin.close();
	return 0;
}






