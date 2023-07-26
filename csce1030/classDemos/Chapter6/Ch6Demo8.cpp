//Passing by reference
#include <iostream>
using namespace std;


void update(int& num)
{
	cout<<"Before inside function:num="<<num<<endl;
	num=20;
	cout<<"After inside function:num="<<num<<endl;
}

int main()
{
	int num=5;
	
	cout<<"Before:num="<<num<<endl;
	
	update(num);
	
	cout<<"After:num="<<num<<endl;
	return 0;
	
}