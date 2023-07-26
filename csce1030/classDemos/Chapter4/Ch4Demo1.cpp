//Loops: allow us to repeat execution of a set of codes

#include <iostream>
using namespace std;

int main()
{
	/*
	cout<<"Hello"<<endl;
	
	cout<<"Hello"<<endl;
	cout<<"Hello"<<endl;
	cout<<"Hello"<<endl;
	cout<<"Hello"<<endl;*/
	
	int count=0; //initialzing condition/statement
	while(count<5) //loop termination condition, loop executes if this is true
	{
		//whatever repeats goes in here
		cout<<"Hello"<<endl;
		count+=1; //update action
		cout<<"count="<<count<<endl;
	}
	
	cout<<"\n*********************************\n";
	//display all number from -12 to 8, inclusive
	
	int number=-12; //initialzing condition/statement
	
	while(number<=8)
	{
		cout<<number<<"\t";
		number+=1; //update action
	}
	cout<<endl;
	
	cout<<"\n*********************************\n";
	//display all even number from 12 to 28, inclusive
	
	number=12; //initialzing condition/statement
	
	while(number<=28)
	{
		cout<<number<<"\t";
		number+=2; //update action
	}
	cout<<endl;

	cout<<"\n*********************************\n";
	
	
	
	
	//display all number from 12 to -8, inclusive
	
	number=12; //initialzing condition/statement
	
	while(number >= -8)
	{
		cout<<number<<"\t";
		number-=1; //update action
	}
	cout<<endl;
	
	
	return 0;
}











