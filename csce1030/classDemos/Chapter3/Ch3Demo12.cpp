#include <iostream>
using namespace std;

int main()
{
	enum Direction {UP='U', DOWN='D', LEFT='L', RIGHT='R'};
	Direction my_dir;
	int x=0, y=0;
	char dir;
	cout<<"Where do you want to move? Enter U for UP, D for DOWN, L for LEFT, R for RIGHT:"; cin>>dir;
	
	my_dir=static_cast<Direction>(dir);
	
	switch(my_dir)
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