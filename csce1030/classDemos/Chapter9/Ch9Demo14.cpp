#include <iostream>
using namespace std;

void getArray(int **arr2D, int r, int c )
{
	cout<<"Enter "<<r*c<<" numbers:";
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			cin>>arr2D[i][j];
		}
		
	}
}

void showArray(int **arr2D, int r, int c)
{
	cout<<"You entered:"<<endl;
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
}


int computeAllSum(int **arr2D, int row, int col)
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


void computeRowSum(int **arr2D , int row, int col, int *row_sum)
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


void computeColSum(int **arr2D , int row, int col, int* col_sum)
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



void dispSum(int* sum_array, int sz)
{
	for (int i=0; i<sz;++i)
	{
		cout<<sum_array[i]<<endl;
	}	
	
}


int main()
{
	//declare a pointer
	int** arr2D;
	int *row_sum;
	int *col_sum;
	
	
	int r,c;
	
	cout<<"How many rows?"; cin>>r;
	cout<<"How many columns?"; cin>>c;
	
	
	//allocate memory
	arr2D=new int*[r];
	for (int i=0;i<r;++i)
	{
		arr2D[i]=new int[c];
	}
	
	row_sum=new int[r];
	col_sum=new int[c];
	
	getArray(arr2D, r,c);
	showArray(arr2D,r,c);
	
	cout<<"Sum of all elements:"<<computeAllSum(arr2D, r,c)<<endl;
	
	computeRowSum(arr2D, r,c, row_sum);
	cout<<"Sum of rows:"<<endl;
	dispSum(row_sum, r);
	
	
	computeColSum(arr2D, r,c, col_sum);
	cout<<"Sum of columns:"<<endl;
	dispSum(col_sum, c);
	
	
	
	//deallocate memory
	for (int i=0;i<r;++i)
	{
		delete [] arr2D[i];
	}
	
	delete [] arr2D;
	
	delete [] row_sum;
	
	delete [] col_sum;
	
	return 0;
}