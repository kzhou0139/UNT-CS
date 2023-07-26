#include <iostream>
using namespace std;

int main()
{
	const int SIZE=7;
	
	int array[SIZE]={6,-8,12,5,3, 21 , 13};
	int max=array[0];
	for(int i=1;i<SIZE;++i)
	{
		if (max < array[i])
		{
			max=array[i];
		}
	}
	cout<<"maximum:"<<max<<endl;
	
	return 0;
}