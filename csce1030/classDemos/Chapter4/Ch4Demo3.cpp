#include <iostream>
using namespace std;

int main()
{
	/*
	int count=0; 
	while(count<5) 
	{
		
		cout<<"Hello"<<endl;
		++count; //or count++; same as count+=1; 
		cout<<"count="<<count<<endl;
	}
	
	cout<<"\n*********************************\n";
	//display all number from -12 to 8, inclusive
	
	int number=-12; 
	
	while(number<=8)
	{
		cout<<number<<"\t";
		++number; //or number++ same as number+=1; 
	}
	cout<<endl;
	
	cout<<"\n*********************************\n";
	
		
	//display all number from 12 to -8, inclusive
	
	number=12; 
	
	while(number >= -8)
	{
		cout<<number<<"\t";
		--number; // or number-- same as number-=1; 
	}
	cout<<endl;*/
	
	
	//++: increment operator
	//--: decrement operator
	
	int x=5;
	++x; //prefix operation
	cout<<"x="<<x<<endl;
	x++; //postfix operation
	cout<<"x="<<x<<endl;
	
	
	//prefix v/s postfix
	x=5;
	//int result=10*++x; //prefix
	int result=10*x++; //postfix
	cout<<"x="<<x<<endl;
	cout<<"result="<<result<<endl;
	
	
	
	
	return 0;
}











