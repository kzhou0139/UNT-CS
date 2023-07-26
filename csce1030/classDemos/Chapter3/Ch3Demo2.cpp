//nesting if-else -- putting one if-else inside another if-else


#include <iostream>
using namespace std;

int main()
{
	
	int number;
	
	cout<<"Enter a number:";
	cin>>number;
		
	if (number%2==0)
	{
		//even
		cout<<"It's even."<<endl;
		if (number%5==0)
		{
			cout<<"It is also divisible by 5."<<endl;
			
		}
		
		else
		{
			cout<<"But it is NOT divisible by 5."<<endl;
		}
	}
	
	else
	{
		//odd
		cout<<"It's odd."<<endl;
			
	}
	
	return 0;
}




