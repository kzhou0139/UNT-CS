#include <iostream>
using namespace std;

int main()
{
	for (int count=0;count<5;++count)
	{
		cout<<"Hello"<<endl;
		cout<<"count="<<count<<endl;		
	}
		
	cout<<"\n*********************************\n";
	//display all number from -12 to 8, inclusive
			
	for (int number=-12; number<=8; ++number)
	{
		cout<<number<<"\t";
	}
	
	cout<<endl;
	
	cout<<"\n*********************************\n";
	//display all even number from 12 to 28, inclusive
	
	for (int number=12;number<=28; number+=2)
	{
		cout<<number<<"\t";
	}
	cout<<endl;
	cout<<"\n*********************************\n";
		
	//display all number from 12 to -8, inclusive
	
	for (int number=12; number >= -8; --number)
	{
		cout<<number<<"\t";	
	}
	cout<<endl;
	
	
	return 0;
}











