#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("result.dat");
	double x=2, y=3;
	double result=x/y;
	
	//cout.setf(ios::fixed);
	cout.setf(ios::scientific);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout<<"Result="<<result<<endl;
	
	int my_int=7;
	cout<<"my_int="<<my_int<<endl;
	
	++my_int;
	cout.setf(ios::showpos);
	cout<<"my_int="<<my_int<<endl;
	
	++my_int;
	cout<<"my_int="<<my_int<<endl;
		
	++my_int;
	cout<<"my_int="<<my_int<<endl;
	
	++my_int;
	cout.unsetf(ios::showpos);
	cout<<"my_int="<<my_int<<endl;
	
	
	
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(4);
	fout<<"Result="<<result<<endl;
	
	fout.close();
	
	return 0;
}





