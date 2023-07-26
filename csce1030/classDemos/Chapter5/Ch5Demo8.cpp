#include <iostream>
using namespace std;

int main()
{
	const int SIZE=7;
	
	int array[SIZE]={6,-8,12,5,3, 21 , 13};
	 // {13, 21, 3,5,12,-8,6}
	/*
	swap: 6,3 array[0], array[SIZE-1]
	swap: 11,-8 array[1], array[SIZE-2]
	swap: 12,5 array[2], array[SIZE-3]
	
	int temp=aray[0];
	array[0]=array[SIZE-1];
	array[SIZE-1]=temp;
	*/
	
	for (int i=0; i<SIZE/2;++i) //works for both odd and even SIZE
	{
		int temp=array[i];
		array[i]=array[(SIZE-1)-i];
		array[(SIZE-1)-i]=temp;
	}
	
	for (int i=0;i<SIZE;++i)
	{
		cout<<array[i]<<"\t";
	}
	
	cout<<endl;
	
	
	return 0;
}