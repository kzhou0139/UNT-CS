#include <iostream>
using namespace std;

int main()
{
	
	int number;
	int sum=0;
	for (int count=0;count<10; ++count)
	{
		cout<<"Enter number #"<<count+1<<":";
		cin>>number;
		sum=sum+number;
	}
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}