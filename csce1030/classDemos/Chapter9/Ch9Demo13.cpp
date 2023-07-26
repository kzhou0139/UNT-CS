#include <iostream>
using namespace std;
//const int ROWS=10;
//const int COLS=10;
int main()
{
	//int arr2D[ROWS][COLS]; //static array
	
	//declare a pointer
	int** arr2D;
	
	
	int r,c;
	
	cout<<"How many rows?"; cin>>r;
	cout<<"How many columns?"; cin>>c;
	
	
	//allocate memory
	arr2D=new int*[r];
	for (int i=0;i<r;++i)
	{
		arr2D[i]=new int[c];
	}
	
	
	cout<<"Enter "<<r*c<<" numbers:";
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			cin>>arr2D[i][j];
		}
		
	}
	
	cout<<"You entered:"<<endl;
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			cout<<arr2D[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	//deallocate memory
	for (int i=0;i<r;++i)
	{
		delete [] arr2D[i];
	}
	
	delete [] arr2D;	
	
	return 0;
}