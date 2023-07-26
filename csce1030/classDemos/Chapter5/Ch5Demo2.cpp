#include <iostream>
using namespace std;

int main()
{
	int score[5];
	
	double sum=0;
	for (int i=0; i<5; ++i)
	{
		cin>>score[i];
		sum+=score[i];
	}
	
	cout<<"Average="<<sum/5<<endl;
	
	
	
	
	
	return 0;
}