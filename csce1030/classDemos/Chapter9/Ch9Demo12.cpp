//pointer vs 2d array

#include <iostream>
using namespace std;

int main()
{
	double arr2D[4][3]={
				{1.71, 2.5, 3.6},
				{5.9, 12.5, -9.6},
				{8.7, 11.3, -8.4},
				{9.5, 2.8, 11.78}
			};
			
	cout<<"arr2D="<<arr2D<<endl; //arr2D is a pointer
	cout<<"*arr2D="<<*arr2D<<endl; //*arr2D is also a pointer
	cout<<"arr2D[0]="<<arr2D[0]<<endl;
	cout<<"**arr2D="<<**arr2D<<endl;
	cout<<"*arr2D[0]="<<*arr2D[0]<<endl;
	
	cout<<"arr2D[0][0]="<<arr2D[0][0]<<endl;
	cout<<"&arr2D[0][0]="<<&arr2D[0][0]<<endl;
	//the name of the 2D array is also a pointer and it is pointing at the first element of the 2D array
	
	cout<<"arr2D+1="<<arr2D+1<<endl; //arr2D+1 is a pointer
	cout<<"*(arr2D+1)="<<*(arr2D+1)<<endl; //*(arr2D+1) is a pointer
	
	cout<<"arr2D[1]="<<arr2D[1]<<endl;
	
	cout<<"**(arr2D+1)="<<**(arr2D+1)<<endl; 
	cout<<"*arr2D[1]="<<*arr2D[1]<<endl;
	
	
	cout<<"arr2D+2="<<arr2D+2<<endl; //arr2D+2 is a pointer
	cout<<"*(arr2D+2)="<<*(arr2D+2)<<endl; //*(arr2D+2) is a pointer
	cout<<"arr2D[2]="<<arr2D[2]<<endl;
	cout<<"**(arr2D+2)="<<**(arr2D+2)<<endl; 
	cout<<"*arr2D[2]="<<*arr2D[2]<<endl;
	
	//In general: array[i]=*(array+i) is a pointer, pointing at first element of the (i+1)th row: row pointers
	
	cout<<"arr2D[0][0]="<<arr2D[2][1]<<endl;
	
	cout<<"*(*(arr2D+2)+1)="<<*(*(arr2D+2)+1)<<endl;
	
	cout<<"*(arr2D[2]+1)="<<*(arr2D[2]+1)<<endl;
	
	return 0;
}