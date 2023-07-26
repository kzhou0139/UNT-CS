#include <iostream>
using namespace std;

int main()
{
	int index;
	double array[6]={1.1, 2.7, 5.6, -8.9, 1.7, 2.5};
	cout<<"Enter index (0-5):"; cin>>index;
	
	cout<<array[index]<<endl;
	
	
	//double array[]={1.1, 2.7, 5.6, -8.9, 1.7, 2.5};
	 
	// double array[6]={1.1, 2.7}; //partial initialize ok, don't depend on this
	
	return 0;
}