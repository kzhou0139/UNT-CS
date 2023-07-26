#include <iostream>
using namespace std;

int main()
{
	int var1=25;
	int var2=45;
	
	int* ptr1;
	int* ptr2;
	
	ptr1=&var1;
	ptr2=&var2;
	
	cout<<"var1="<<var1<<"\tvar2="<<var2<<endl;
	cout<<"&var1="<<&var1<<"\t&var2="<<&var2<<endl;
	cout<<"ptr1="<<ptr1<<"\tptr2="<<ptr2<<endl;
	cout<<"*ptr1="<<*ptr1<<"\t*ptr2="<<*ptr2<<endl;
	
	/*
	cout<<"\n****************************************\n";
	ptr1=ptr2;
	cout<<"ptr1="<<ptr1<<"\tptr2="<<ptr2<<endl;
	cout<<"*ptr1="<<*ptr1<<"\t*ptr2="<<*ptr2<<endl;
	cout<<"var1="<<var1<<"\tvar2="<<var2<<endl;
	cout<<"&var1="<<&var1<<"\t&var2="<<&var2<<endl;
	*/
	
	cout<<"\n****************************************\n";
	*ptr1=*ptr2;
	cout<<"ptr1="<<ptr1<<"\tptr2="<<ptr2<<endl;
	cout<<"*ptr1="<<*ptr1<<"\t*ptr2="<<*ptr2<<endl;
	cout<<"var1="<<var1<<"\tvar2="<<var2<<endl;
	cout<<"&var1="<<&var1<<"\t&var2="<<&var2<<endl;
	
	return 0;
}