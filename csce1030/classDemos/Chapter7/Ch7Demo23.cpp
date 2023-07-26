#include <iostream>
#include <fstream>
using namespace std;
const int SIZE=10;

int main()
{
	ifstream fin;
	string fname[SIZE], lname[SIZE];
	char gender[SIZE];
	int age[SIZE];
	double salary[SIZE];
	double sum_sal=0;
	fin.open("data.dat");
	int count=0;
	int females=0;
	while(fin>>fname[count]>>lname[count]>>gender[count]>>age[count]>>salary[count])
	{
		++count;
	}
	
	cout<<"before sorting:"<<endl;
	for (int i=0;i<count;++i)
	{
		cout<<fname[i]<<"\t"<<lname[i]<<"\t"<<gender[i]<<"\t"<<age[i]<<"\t"<<salary[i]<<endl;
		
	}
	
	//sort
	for (int i=0;i<count;++i)
	{
		for (int j=i+1;j<count;++j)
		{
			if (salary[i]>salary[j])
			{
				double temp=salary[i];
				salary[i]=salary[j];
				salary[j]=temp;
			}
			
		}
		
	}
	cout<<"\n************************************\n";
	
	cout<<"after sorting:"<<endl;
	for (int i=0;i<count;++i)
	{
		cout<<fname[i]<<"\t"<<lname[i]<<"\t"<<gender[i]<<"\t"<<age[i]<<"\t"<<salary[i]<<endl;
		
	}
	
	
	fin.close();
		
	return 0;
	
}