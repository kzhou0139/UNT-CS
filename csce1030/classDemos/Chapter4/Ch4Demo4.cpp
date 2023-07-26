#include <iostream>
using namespace std;

int main()
{
	
	//do-while loop
	int count=0; //initialzing condition/statement
	
	do
	{
		cout<<"Hello"<<endl;
		count+=1; //update action
		cout<<"count="<<count<<endl;
		
	}while(count<5); //loop termination condition, loop executes if this is true
	
	
	cout<<"\n*********************************\n";
	//display all number from -12 to 8, inclusive
	
	int number=-12; //initialzing condition/statement
	
	do
	{
		cout<<number<<"\t";
		number+=1; //update action
	}while(number<=8);
	cout<<endl;
	
	cout<<"\n*********************************\n";
	//display all even number from 12 to 28, inclusive
	
	number=12; //initialzing condition/statement
	
	do
	{
		cout<<number<<"\t";
		number+=2; //update action
	}while(number<=28);
	cout<<endl;

	cout<<"\n*********************************\n";
		
	
	//display all number from 12 to -8, inclusive
	
	number=12; //initialzing condition/statement
	do
	{
		cout<<number<<"\t";
		number-=1; //update action
	}while(number >= -8);
	cout<<endl; 
	
	do
	{
		cout<<"This will never execute."<<endl;
	}while(false);
	
	
	return 0;
}











