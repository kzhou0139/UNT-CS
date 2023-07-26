#include <iostream>
using namespace std;

int main()
{
	int x=0, y=0;
	int dir;
	cout<<"Where do you want to move? Enter 0 for UP, 1 for DOWN, 2 for LEFT, 3 for RIGHT:"; cin>>dir;
	
	switch(dir)
	{
		case 0:
			y+=1;
			break;
		
		case 1:
			y-=1;
			break;
		
		case 2:
			x-=1;
			break;
		
		case 3:
			x+=1;
			break;
		
		default:
			cout<<"Wrong choice."<<endl;
			break;
		
	}
	cout<<"Updated position:("<<x<<","<<y<<")"<<endl;
	
	return 0;
}