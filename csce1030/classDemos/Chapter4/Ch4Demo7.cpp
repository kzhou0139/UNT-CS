#include <iostream>
using namespace std;

int main()
{
	
	int number;
	int sum=0;
	
	char answer;
	
	do
	{
		cout<<"Enter number:";
		cin>>number;
		sum=sum+number;
		
		cout<<"Do you have more numbers to add?Y/N:"; cin>>answer;
	}while(answer=='Y');
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}