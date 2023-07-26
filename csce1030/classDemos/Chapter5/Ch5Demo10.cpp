#include <iostream>
using namespace std;

int main()
{
	const int SIZE=7;
	
	int array[SIZE]={6,-8,12,5,3, 21 , 13};
	
	//21 X X X X X X
	
	for(int i=1;i<SIZE;++i)
	{
		if (array[0] < array[i])
		{
			int temp=array[0];
			array[0]=array[i];
			array[i]=temp;
		}
		/* if you want to see intermediate outputs 
		for(int j=0;j<SIZE;++j)
		{
			cout<<array[j]<<"\t";
		}
		cout<<endl;*/
	}
	
	for(int i=0;i<SIZE;++i)
	{
		cout<<array[i]<<"\t";
	}
	cout<<endl;
	
	return 0;
}