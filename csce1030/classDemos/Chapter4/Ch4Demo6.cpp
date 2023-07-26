#include <iostream>
using namespace std;

int main()
{
	
	int number;
	int sum=0;
	
	char answer='Y';
	
	while(answer=='Y')
	{
		cout<<"Enter number:";
		cin>>number;
		sum=sum+number;
		
		cout<<"Do you have more numbers to add?Y/N:"; cin>>answer;
	}
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}