#include <iostream>
using namespace std;

int main()
{
	int array1D[5];
	array1D[0]=25;
	
	int array2D[3][4]; //data type: int, array name:array2D, # of rows=3, # of columns=4	
	array2D[0][0]=25; //first row, first column
	array2D[2][2]=36; //third row, third column
	
	
	double arr[4]={1.1,2.3,3.5,4.65};
	//2D array intialization
	double arr2D[4][3]={
						{1.1, 2.3, 5.6}, 
						{2.35, 5.69, -6.45}, 
						{11.25, 3.78, 9.56}, 
						{1.255, 12.33, 7.45}
						};
						
	int row_index, col_index;
	
	cout<<"Enter row_index and col_index:"; cin>>row_index>>col_index;
	
	cout<<"Data:"<<arr2D[row_index][col_index]<<endl;
	
	return 0;
}




