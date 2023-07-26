#include <iostream>
using namespace std;

int main()
{
	/*for 1D array
	
	int arr[5];
	for (int i=0;i<5;++i)
	{
		cin>>arr[i];
	}
	
	*/
	
	int arr2D[3][5];
	cout<<"Enter 15 numbers:";
	for(int i=0; i<3;++i)
	{
		for (int j=0; j<5;++j)
		{
			cin>>arr2D[i][j];
		}
	}
	
	
	for(int i=0; i<3;++i)
	{
		for (int j=0; j<5;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	return 0;
}