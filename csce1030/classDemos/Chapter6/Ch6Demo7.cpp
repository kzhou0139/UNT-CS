//Local variable vs Global variable
//Local constants vs global constants
#include <iostream>
using namespace std;

//int num; //global variable, GLOBAL VARIABLES ARE FORBIDDEN FROM USE
const int  MY_GLOBAL_CONST=30; //global constants, you can use them

void update(int num)
{
	const int MY_LOCAL_CONST=25;
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
	
	//cout<<MY_LOCAL_CONST<<endl; //compilation error, outside scope
	return 0;
	
}