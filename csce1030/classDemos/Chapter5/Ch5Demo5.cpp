#include <iostream>
using namespace std;

int main()
{
	const int SIZE=6;
	
	int source[SIZE]={6,-8,12,5,11,3};
	int dest[SIZE];
	
	//dest=source; //cannot assign one array to another to make them equal
	/*
	dest[0]=source[0];
	dest[1]=source[1];
	......................
	.....................
	dest[SIZE-1]=source[SIZE-1];
	*/
	for (int i=0; i<SIZE;++i)
	{
		dest[i]=source[i];
	}
	
	for (int i=0;i<SIZE;++i)
	{
		cout<<dest[i]<<"\t";
	}
	
	cout<<endl;
	
	
	return 0;
}