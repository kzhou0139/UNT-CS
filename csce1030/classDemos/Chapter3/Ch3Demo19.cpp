#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x=2, y=3;
	
	if ((fabs(x/y-0.666))<1e-5)
	{
		//do something
		cout<<"Do something."<<endl;
	}
	else
	{
		//do something else
		cout<<"Do something else."<<endl;
		
	}
	
	
	
	
	return 0;
}