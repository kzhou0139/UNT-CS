//Static memory: allocated during compilation, compile time memory, fixed size, allocated in stack
//Dynamic memory: allocated during run time, run time memory, variable memory size, allocated in heap/freestore

#include <iostream>
using namespace std;

int main()
{
	int my_var=20; //static memory, static variable
	
	//dynamic memory: new and delete operators 
	int* ptr; //declare a pointer
	
		
	ptr=new int; //dynamic memory allocation
	
	*ptr=78; //dynamic variable
	
	cout<<"ptr="<<ptr<<endl;
	cout<<"*ptr="<<*ptr<<endl;
	
	int some_value=*ptr+20;
	
	*ptr=5;
	cout<<"ptr="<<ptr<<endl;
	cout<<"*ptr="<<*ptr<<endl;
	
	for (int i=0;i<*ptr;++i)
	{
		cout<<"print this"<<endl;
	}
	
	
	delete ptr; //deallocation of dynamic memory
	
	
	return 0;
}