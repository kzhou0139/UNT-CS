#include <iostream>
#include <fstream>
using namespace std;
const int SIZE=10;

struct Employee
{
	string fname;
	string lname;
	char gender;
	int age;
	double salary;
};

int main()
{
	ifstream fin;
	
	Employee emp[SIZE];
	
	double sum_sal=0;
	fin.open("data2.dat");
	int count=0;
	int females=0;
	while(fin>>emp[count].fname>>emp[count].lname>>emp[count].gender>>emp[count].age>>emp[count].salary)
	{
		++count;
	}
	
	cout<<"before sorting:"<<endl;
	for (int i=0;i<count;++i)
	{
		cout<<emp[i].fname<<"\t"<<emp[i].lname<<"\t"<<emp[i].gender<<"\t"<<emp[i].age<<"\t"<<emp[i].salary<<endl;
		
	}
	
	//sort
	for (int i=0;i<count;++i)
	{
		for (int j=i+1;j<count;++j)
		{
			if (emp[i].salary>emp[j].salary)
			{
				Employee temp=emp[i];
				emp[i]=emp[j];
				emp[j]=temp;
			}
			
		}
		
	}
	cout<<"\n************************************\n";
	
	cout<<"after sorting:"<<endl;
	for (int i=0;i<count;++i)
	{
		cout<<emp[i].fname<<"\t"<<emp[i].lname<<"\t"<<emp[i].gender<<"\t"<<emp[i].age<<"\t"<<emp[i].salary<<endl;
	
	}
	
	
	fin.close();
		
	return 0;
	
}