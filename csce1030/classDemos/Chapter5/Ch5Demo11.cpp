//bubble sorting
#include <iostream>
using namespace std;

int main()
{
	const int SIZE=7;
	
	int array[SIZE]={6,-8,-12,5,3, 1 , 13};
	
	for(int i=0; i<SIZE;++i)
	{
		for(int j=i+1;j<SIZE;++j)
		{
			if (array[i] < array[j])
			{
				int temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		
		}
	}
	
	
	for(int i=0;i<SIZE;++i)
	{
		cout<<array[i]<<"\t";
	}
	cout<<endl;
	
	return 0;
}