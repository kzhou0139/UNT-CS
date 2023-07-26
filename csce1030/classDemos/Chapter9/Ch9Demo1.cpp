#include <iostream>
using namespace std;

int main()
{
	int var=20;
	cout<<"Value: var="<<var<<endl;
	cout<<"Address: &var="<<&var<<endl; //&: reference operator, address operator
	
	int* address=&var;
	
	//Pointer variables store address
	cout<<"address="<<address<<endl;
	cout<<"*address="<<*address<<endl; //*: dereference operator
	
	*address=89;
	cout<<"*address="<<*address<<endl;
	cout<<"Value: var="<<var<<endl;
	
	
	return 0;
}