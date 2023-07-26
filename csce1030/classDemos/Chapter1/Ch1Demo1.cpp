/* --block comment
Algorithm

1. Get the radius from the user
2. Get the height from the user
3. Multiply square of radius, height and pi and store
the product in volume
4. Give the result to the user
*/

#include <iostream>
using namespace std;


int main()
{
	//here i decalre variables --single line comment
	float radius;
	float height;
	float volume;
	
	cout<<"Enter radius:";
	cin>>radius;
	cout<<"Enter height:";
	cin>>height;
	volume=3.1416*radius*radius*height;
	//cascaded cout statements -- single line comment
	cout<<"Volume is:"<<volume<<endl;
	
	
	/* --block comment
	cout<<"Volume is:";
	cout<<volume;
	cout<<endl;
	*/
	
	return 0;
}











