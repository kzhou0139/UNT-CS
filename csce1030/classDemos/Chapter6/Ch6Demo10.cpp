#include <iostream>
#include <cmath>
using namespace std;

void second(int& result, int x)
{
	cout<<"Inside funtion second"<<endl;
	result=pow(x,5)+3*pow(x,3)+10;
	cout<<"Returning from second"<<endl;
}

double first(int x)
{
	cout<<"Inside function first"<<endl;
	int result;
	cout<<"Calling function second"<<endl;
	second(result, x);
	cout<<"Back to first"<<endl;
	cout<<"Returning from first"<<endl;
	return(sqrt(result));
	
}

int main()
{
	cout<<"Inside main"<<endl;
	int x=10;
	cout<<"Calling function first:"<<endl;
	cout<<"Calculated result:"<<first(x)<<endl;
	cout<<"Back to main"<<endl;
	return 0;
	
}