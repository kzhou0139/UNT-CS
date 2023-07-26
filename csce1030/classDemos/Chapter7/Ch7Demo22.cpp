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
	
	for (int i=0;i<count;++i)
	{
		cout<<fname[i]<<"\t"<<lname[i]<<"\t"<<gender[i]<<"\t"<<age[i]<<"\t"<<salary[i]<<endl;
		sum_sal+=salary[i];
		if (gender[i]=='F')
		{
			++females;
		}
	}
	cout<<"Average salary="<<sum_sal/count<<endl;
	cout<<"# of females="<<females<<endl;
	
	double max_sal=salary[0];
	string max_earner=fname[0]+" "+lname[0];
	for (int i=1;i<count;++i)
	{
		if (max_sal<salary[i])
		{
			max_sal=salary[i];
			max_earner=fname[i]+" "+lname[i];
		}
	}
	
	cout<<"Maximum salary:"<<max_sal<<endl;
	cout<<"Maximum earner:"<<max_earner<<endl;
	
	fin.close();
		
	return 0;
	
}