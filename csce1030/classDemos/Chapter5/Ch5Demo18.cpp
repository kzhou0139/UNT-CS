#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	
	//length of C-string
	char cstr[]="This is a C-String!!!";
	int length=strlen(cstr);
	cout<<"Length="<<length<<endl;
	
	//copying C-string
	char source[20]="Hello friend";
	char dest[20];
	
	// dest=source; // if C++ strings, doesn't work with C-strings
	
	strcpy(dest, source);
	cout<<"dest="<<dest<<endl;
	
	strcpy(dest, "Updated"); //can't do dest="updated"
	cout<<"dest="<<dest<<endl;
	
	//concat C-strings
	
	char cstr1[40]="Hello";
	char cstr2[20]=" friend!!!";
	strcat(cstr1, cstr2);
	cout<<"cstr1="<<cstr1<<endl;
	
	strcpy(cstr1, "hello");
	
	strcat(cstr1, " my friend!!!");
	cout<<"cstr1="<<cstr1<<endl;
	
	//comparing C-strings
	char cstr3[]="Test";
	char cstr4[]="test";
	
	if (strcmp(cstr3,cstr4))
	{
		cout<<"Output 1"<<endl;
		
	}
	else
	{
		cout<<"Output 2"<<endl;
	}
	
	int result=strcmp(cstr3,cstr4);
	cout<<"result="<<result<<endl;
	
	
	return 0;
}










