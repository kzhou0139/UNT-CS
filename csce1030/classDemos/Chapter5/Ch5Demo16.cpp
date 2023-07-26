#include <iostream>
using namespace std;

int main()
{
	const int ROW_SIZE=10;
	const int COL_SIZE=10;
	
	int arr2D[ROW_SIZE][COL_SIZE];
	int row_sum[ROW_SIZE];
	int col_sum[COL_SIZE];
	int row, col;
	cout<<"How many rows?"; cin>>row; //cannot be greater than ROW_SIZE
	cout<<"How many columns?"; cin>>col; //cannot be greater than COL_SIZE
	
	cout<<"Enter "<<row*col<<" numbers:";
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			cin>>arr2D[i][j];
		}
	}
	
	int sum=0;
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			sum+=arr2D[i][j];
		}
	}
	cout<<"Sum of all numbers="<<sum<<endl;
	
	
	cout<<"Sum of rows:"<<endl; 
	for(int i=0; i<row;++i)
	{
		row_sum[i]=0;
		for (int j=0; j<col;++j)
		{
			row_sum[i]+=arr2D[i][j];
		}
	}
	
	for (int i=0; i<row;++i)
	{
		cout<<row_sum[i]<<endl;
	}
	
	cout<<"Sum of columns:"<<endl;
	
	for (int j=0; j<col;++j)
	{
		col_sum[j]=0;
	}
	
	for(int i=0; i<row;++i)
	{
		
		for (int j=0; j<col;++j)
		{
			col_sum[j]+=arr2D[i][j];
		}
	}
	
	for (int j=0; j<col;++j)
	{
		cout<<col_sum[j]<<endl;;
	}
	
	cout<<"The array is:"<<endl;
	
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	return 0;
}