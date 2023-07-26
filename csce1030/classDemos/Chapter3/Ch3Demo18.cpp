#include <iostream>
using namespace std;

int main()
{
	int x=30, y=20;
	/*
	if (x>y)
	{
		cout<<"x is bigger than y."<<endl;
	}
	else
	{
		cout<<"x is NOT bigger than y."<<endl;
	}*/
	
	(x>y)?cout<<"x is bigger than y."<<endl:cout<<"x is NOT bigger than y."<<endl;
	return 0;
}