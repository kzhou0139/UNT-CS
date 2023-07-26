#include <iostream>
using namespace std;
const int ROW_SIZE=10;
const int COL_SIZE=10;
void getArray(int arr2D[][COL_SIZE] , int& row, int& col)
{
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
	
}

void showArray(int arr2D[][COL_SIZE] , int row, int col)
{
	cout<<"The array is:"<<endl;
	
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int computeAllSum(int arr2D[][COL_SIZE] , int row, int col)
{
	int sum=0;
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			sum+=arr2D[i][j];
		}
	}
	return (sum);
}


void computeRowSum(int arr2D[][COL_SIZE] , int row, int col, int row_sum[])
{
	for(int i=0; i<row;++i)
	{
		row_sum[i]=0;
		for (int j=0; j<col;++j)
		{
			row_sum[i]+=arr2D[i][j];
		}
	}
	
}


void computeColSum(int arr2D[][COL_SIZE] , int row, int col, int col_sum[])
{
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
	
}

/* replace with generic dispSum
void dispRowSum(int row_sum[], int row)
{
	for (int i=0; i<row;++i)
	{
		cout<<row_sum[i]<<endl;
	}	
	
}


void dispColSum(int col_sum[], int col)
{
	for (int j=0; j<col;++j)
	{
		cout<<col_sum[j]<<endl;;
	}
	
}
*/

void dispSum(int sum_array[], int sz)
{
	for (int i=0; i<sz;++i)
	{
		cout<<sum_array[i]<<endl;
	}	
	
}

int main()
{

	
	int arr2D[ROW_SIZE][COL_SIZE];
	int row_sum[ROW_SIZE];
	int col_sum[COL_SIZE];
	int row, col;
	
	
	/* moved to getArray
	cout<<"How many rows?"; cin>>row; //cannot be greater than ROW_SIZE
	cout<<"How many columns?"; cin>>col; //cannot be greater than COL_SIZE
	
	cout<<"Enter "<<row*col<<" numbers:";
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			cin>>arr2D[i][j];
		}
	}*/
	getArray(arr2D , row, col);
	
	/*
	int sum=0;
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			sum+=arr2D[i][j];
		}
	}
	cout<<"Sum of all numbers="<<sum<<endl;
	*/
	cout<<"Sum of all numbers:"<<computeAllSum(arr2D , row, col)<<endl;
	
	
	/* moved to computeRowSum
	for(int i=0; i<row;++i)
	{
		row_sum[i]=0;
		for (int j=0; j<col;++j)
		{
			row_sum[i]+=arr2D[i][j];
		}
	}*/
	computeRowSum(arr2D , row, col, row_sum);
	
	cout<<"Sum of rows:"<<endl; 
	/* moved to dispRowSum
	for (int i=0; i<row;++i)
	{
		cout<<row_sum[i]<<endl;
	}*/
	//dispRowSum(row_sum, row);
	dispSum(row_sum, row);
	
	/* moved to computeColSum
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
	}*/
	computeColSum(arr2D , row, col, col_sum);
	
	cout<<"Sum of columns:"<<endl;
	/*moved to dispColSum
	for (int j=0; j<col;++j)
	{
		cout<<col_sum[j]<<endl;;
	}*/
	
	//dispColSum(col_sum, col);
	dispSum(col_sum, col);
	
	/*
	cout<<"The array is:"<<endl;
	
	for(int i=0; i<row;++i)
	{
		for (int j=0; j<col;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}*/
	showArray(arr2D , row, col);
	
	
	return 0;
}