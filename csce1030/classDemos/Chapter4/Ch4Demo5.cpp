#include <iostream>
using namespace std;

int main()
{
	int count=0;
	int number;
	int sum=0;
	int how_many;
	cout<<"How many numnbers to add?"; cin>>how_many;
	
	while(count<how_many)
	{
		cout<<"Enter number #"<<count+1<<":";
		cin>>number;
		sum=sum+number;
		count+=1;
	}
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}