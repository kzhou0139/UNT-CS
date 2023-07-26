#include <iostream>
using namespace std;

int main()
{
	const int SIZE=6;
	
	int source[SIZE]={6,-8,12,5,11,3};
	int dest[SIZE]; // {3,11,5,12,-8,6}
	
	
	/*
	dest[0]=source[SIZE-1];
	dest[1]=source[SIZE-2];
	dest[2]=source[SIZE-3];
	......................
	.....................
	dest[SIZE-1]=source[0];
	*/
	
	for (int i=0; i<SIZE;++i)
	{
		dest[i]=source[(SIZE-1)-i];
	}
	
	for (int i=0;i<SIZE;++i)
	{
		cout<<dest[i]<<"\t";
	}
	
	cout<<endl;
	
	
	return 0;
}