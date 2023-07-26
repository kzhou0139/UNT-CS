#include <iostream>
using namespace std;
int main()
{
	
	enum Colors {Red, Blue, Green}; //Colors is a data type
	
	Colors my_color;
	my_color=Red; //my_color=Blue or my_color=Green
	
	//my_color=Yellow; // Yellow is not in the list
	
	
	enum Days {Sunday=50, Monday, Friday, Saturday}; //Days is a data type
	
	Days my_day;
	
	my_day=51;
	
	//my_day=Tuesday; // Tuesday is not in the list
	
	cout<<"my_day="<<Friday<<endl;
	
		
	
	
	
	return 0;
}