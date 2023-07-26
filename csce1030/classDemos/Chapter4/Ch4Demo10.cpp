#include <iostream>
using namespace std;

int main()
{
	int number;
	int sum=0;
	int how_many;
	cout<<"How many numnbers to add?"; cin>>how_many;
	for (int count=0;count<how_many; ++count)
	{
		cout<<"Enter number #"<<count+1<<":";
		cin>>number;
		sum=sum+number;
	}
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}