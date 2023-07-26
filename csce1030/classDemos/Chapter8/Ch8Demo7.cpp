#include <iostream>
using namespace std;


struct Student
{
	string name;
	int tests[5];
	double average;
};

int main()
{
	Student st;
	
	st.name="John Smith";
	st.tests[0]=100;
	st.tests[1]=99;
	st.tests[2]=98;
	st.tests[3]=100;
	st.tests[4]=88;
	
	st.average=(st.tests[0]+st.tests[1]+st.tests[2]+st.tests[3]+st.tests[4])/5.0;
	
	cout<<"Data for student #1:";
	cout<<"Name:"<<st.name<<"\tScores:"<<st.tests[0]<<" "<<st.tests[1]<<" "<<st.tests[2]
	<<" "<<st.tests[3]<<" "<<st.tests[4]<<"\tAverage:"<<st.average<<endl;
	
	
	Student st2;
	double sum=0;
	cout<<"Enter name:"; getline(cin, st2.name);
	cout<<"Enter 5 test scores:";
	for (int i=0;i<5;++i)
	{
		cin>>st2.tests[i];
		sum+=st2.tests[i];
	}
	st2.average=sum/5;
	
	
	cout<<"Data for student #2:";
	cout<<"Name:"<<st2.name<<"\tScores:";
	
	for (int i=0;i<5;++i)
	{
		cout<<st2.tests[i]<<" ";
	}
	cout<<"\tAverage:"<<st2.average<<endl;
	
	
	
	
	return 0;
}