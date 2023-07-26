#include <iostream>

using namespace std;

int main()
{
	//C++ string
	string str="Hello world";
	
	
	//character array
	char ch_arr1[5]={'H', 'e', 'l', 'l', 'o'};
	
	//C-string
	char ch_arr2[6]={'H', 'e', 'l', 'l', 'o', '\0'}; // \0: null character
	char cstr[]="Hello world!!!";
	cout<<cstr<<endl;
	
	/* only reads a single word
	cout<<"Enter a C-string:";
	cin>>cstr;
	cout<<"You entered:"<<cstr<<endl;
		*/
	
	//getline(cin, str); //for C++ srtings
	
	
	char cstr2[80];
	cout<<"Enter a C-string:";
	cin.getline(cstr2, 79);
	cout<<"You entered:"<<cstr2<<endl;
		
	return 0;
}