#include <iostream>
using namespace std;

const int ROWS=2;
const int COLS=4;

void getArray(double arr[][COLS])
{
	ifstream fin;
	fin.open("num.dat");
	for (int i=0;i<ROWS;++i)
	{
		for (int j=0;j<COLS;++j)
		{
			//cin>>arr[i][j];
			fin>>arr[i][j];
			
		}
		
	}
	
	fin.close();
	
}


int sumArray(double arr[][COLS])
{
	int sum=0;
	for (int i=0;i<ROWS;++i)
	{
		for (int j=0;j<COLS;++j)
		{
			sum+=arr[i][j];
			
		}
		
	}
	
	return sum;
}


int main()
{
	double arr[ROWS][COLS];
	
	
	//check fail
	
	getArray(arr);
	
	cout<<"Sum of all numbers in the file:"<<sumArray(array)<<endl;
	
	
	
	return 0;
}