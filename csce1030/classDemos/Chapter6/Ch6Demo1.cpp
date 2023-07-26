#include <iostream>
using namespace std;

int add5(int num) //function header, return type:int,  name: add5, parameter list: int num
{		
	//function body
	int result=num+5;	
	return result; //return statement
	//return (num+5);
}


int main()
{
	int num;
	
	cout<<"Enter number:"; cin>>num;
	
	int result=add5(num); //function call
	
	
	
	//int result=num+5; //moved to the function
	
	cout<<"result="<<result<<endl;
	
	
	result=add5(20);
	
	cout<<add5(30)<<endl;
	
	return 0;
}











