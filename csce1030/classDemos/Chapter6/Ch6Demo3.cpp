#include <iostream>
using namespace std;

void add5(int num) 
{		
	
	int result=num+5;
	cout<<"result="<<result<<endl;	
	//return; //optional return
}


int main()
{
	int num;
	
	cout<<"Enter number:"; cin>>num;
	
	add5(num); //function call
	
	//int result=num+5; //moved to the function
	
	//cout<<"result="<<result<<endl; //moved to the function
	
	
	return 0;
}