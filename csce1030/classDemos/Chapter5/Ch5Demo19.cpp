#include <iostream>
#include <cstring>
using namespace std;

int main()
{

	char source[100]="Hello friend fsjfhdk afhskajfd sfdahskajfh asf";
	char dest[20];
	
	//strcpy(dest, source);
	
	strncpy(dest, source, 10 );
	dest[10]='\0';
	cout<<"dest="<<dest<<endl;
	
	char cstr1[20]="Hello ";
	char cstr2[100]="my friend fdhskajfhksja hfksdhafkjs ahfjkshakfjh";
	//strcat(cstr1, cstr2);
	strncat(cstr1, cstr2, 10);
	cout<<"cstr1="<<cstr1<<endl;
	
	
	return 0;
	
}