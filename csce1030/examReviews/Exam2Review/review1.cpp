#include <iostream>
#include <fstream>

using namespace std;

//declare and define

int findMax(int array[], int count);
int main()
{
	ifstream fin; //if reading
	ofstream  fout; //if writing
	
	fin.open("somename");
	
	fout.open("someothername");
	
	if (fin.fail())
	{
		//message
		exit(1);
	}
	
	//same for fout
	
	//numeric data
	int num;
	fin>>num; //reads a number
	int arr[SIZE];
	int count=0;
	while(fin>>num)
	{
		arr[count]=num;
		++count;
	}
	
	cout<<"Max="<<findMax(array, count)<<endl;
	fout.width(50); //setw
	fout<</*setw(50)<<*/"Max="<<findMax(array, count)<<endl;
	//text data
	char ch;
	ch=fin.get(); //reads a chracter
	
	while(!fin.eof())
	{
		ch=fin.get();
		if (isdigit(ch))
		{
			++digits;
			//fout<<ch;
			fout.put(ch);
		}
		
	}
	cout<<"# of digits="<<digits<<endl;
		
	fin.close();
	fout.close();
	
	
	return 0;
}


int findMax(int array[], int count)
{
	int max;
	
	for (int i=1;i<count;++i)
	{
		if (max<array[i])
		{
			max=array[i];
		}
		
	}
	return max;
}