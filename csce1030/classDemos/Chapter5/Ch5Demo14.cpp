#include <iostream>
using namespace std;

int main()
{
	const int ROW_SIZE=3;
	const int COL_SIZE=5;
	
	int arr2D[ROW_SIZE][COL_SIZE];
	cout<<"Enter 15 numbers:";
	for(int i=0; i<ROW_SIZE;++i)
	{
		for (int j=0; j<COL_SIZE;++j)
		{
			cin>>arr2D[i][j]; //arr2D[i][j]=rand()% +  1; to randomize array
		}
	}
	
	
	for(int i=0; i<ROW_SIZE;++i)
	{
		for (int j=0; j<COL_SIZE;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	return 0;
}