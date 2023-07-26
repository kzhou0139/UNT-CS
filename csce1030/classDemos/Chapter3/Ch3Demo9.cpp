#include <iostream>
using namespace std;

int main()
{
	enum Direction {UP, DOWN, LEFT, RIGHT};
	int x=0, y=0;
	int dir;
	cout<<"Where do you want to move? Enter 0 for UP, 1 for DOWN, 2 for LEFT, 3 for RIGHT:"; cin>>dir;
	
	switch(dir)
	{
		case UP:
			y+=1;
			break;
		
		case DOWN:
			y-=1;
			break;
		
		case LEFT:
			x-=1;
			break;
		
		case RIGHT:
			x+=1;
			break;
		
		default:
			cout<<"Wrong choice."<<endl;
			break;
		
	}
	cout<<"Updated position:("<<x<<","<<y<<")"<<endl;
	
	return 0;
}