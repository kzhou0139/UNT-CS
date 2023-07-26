#include <iostream>
using namespace std;

int main()
{
	/*
	for (int i=0; i<5;++i)
	{
		cout<<"i="<<i<<endl;
		if (i==2)
		{
			break; //stops the loop from executing any further
		}
			
	}*/
	
	for (int i=0; i<5;++i)
	{
		cout<<"i="<<i<<endl;
		if (i==2)
		{
			continue; //skips current iteration of the loop
		}
		cout<<"Some other output."<<endl;
		
	}
	
	cout<<"Outside loop."<<endl;
	
	
	return 0;
}