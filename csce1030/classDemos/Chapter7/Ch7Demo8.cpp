#include <iostream>
#include <fstream>
using namespace std;

const int SIZE=50;
int main()
{
	ifstream fin;
	fin.open("input.txt");
	
	
	if(fin.fail()) 
	{
		cout<<"File error."<<endl;
		exit(1); 
	}
	
	
	int num[SIZE];
	int sum=0;
	
	int count=0;
	while(fin>>num[count])
	{
		++count;
	}
		
	for (int i=0;i<count;++i)
	{
		sum+=num[i];
	}
	
	cout<<"You read:";
	for (int i=0;i<count;++i)
	{
		cout<<num[i]<<endl;
	}
	cout<<"Sum="<<sum<<endl;
	cout<<"Average="<<static_cast<double>(sum)/count<<endl;
	
	
	fin.close();
	return 0;
}






