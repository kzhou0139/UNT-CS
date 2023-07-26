#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	
	int random;
	//seed the random number
	srand(time(NULL));
	random=rand();
	//cout<<"random="<<random<<endl;
	
	int roll;
	roll=rand()%6+1;
	cout<<"roll="<<roll<<endl;
	
	//generate seeded random numbers between 13 and 29 inclusive
	random=rand()% 17 + 13 ;
	cout<<"random="<<random<<endl;
	
	return 0;
}