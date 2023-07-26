#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc==3)
	{
		int sum=atoi(argv[1])+atoi(argv[2]);
		cout<<sum<<endl;
	}
	else
	{
		cout<<"Enter exactly two arguments."<<endl;
	}
	
	
	return 0;
}