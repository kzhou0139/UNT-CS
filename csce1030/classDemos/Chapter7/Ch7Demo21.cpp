#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	string fname, lname;
	char gender;
	int age;
	double salary;
	double sum_sal=0;
	fin.open("data.dat");
	int count=0;
	int females=0;
	while(fin>>fname>>lname>>gender>>age>>salary)
	{
		cout<<fname<<"\t"<<lname<<"\t"<<gender<<"\t"<<age<<"\t"<<salary<<endl;
		sum_sal+=salary;
		++count;
		if (gender=='F')
		{
			++females;
		}
	}
	
	cout<<"Average salary="<<sum_sal/count<<endl;
	cout<<"# of females="<<females<<endl;
	fin.close();
		
	return 0;
	
}