//Program: Get a numebr from the user and determine if its odd or even

/*
Algorithm:
1. Get the number from the user
2. Divide the number by 2 and check the remainder
3. is remainder 0?
	True: It's even
	False: It's odd
*/

#include <iostream>
using namespace std;

int main()
{
	/*
	if (condition such as is it raining?)
	{
		we drive
	}
	else
	{
		we walk
		
	}
	*/
	int number;
	
	cout<<"Enter a number:";
	cin>>number;
	int remainder=number%2;
	
	if (remainder==0)//is remainder 0?
	{
		//even
		cout<<"It's even."<<endl;
	}
	
	else
	{
		//odd
		cout<<"It's odd."<<endl;
		
	}
	
	return 0;
}



