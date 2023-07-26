#include <iostream>
using namespace std;

int main()
{
	/*
	string line;
	int num;
	string dummy;
	
	cout<<"Enter number:"; cin>>num;
	//getline (cin, dummy);
	cin.ignore();
	cout<<"Enter line:"; getline(cin, line);
	
	
	cout<<"Line:"<<line<<endl;
	cout<<"Number:"<<num<<endl;	
	*/
	
	string name[5];
	string age[5];
	string dummy;
	for (int i=0;i<5;++i)
	{
		cout<<"Data for person #"<<i+1<<":"<<endl;
		cout<<"Enter name:"; getline(cin, name[i]);
		cout<<"Enter age:"; cin>>age[i];
		//getline (cin, dummy);
		cin.ignore();
	}
	
	for (int i=0;i<5;++i)
	{
		cout<<"Data for person #"<<i+1<<":"<<endl;
		cout<<"Name:"<<name[i]<<"Age:"<<age[i]<<endl;
	}
	
	return 0;
}