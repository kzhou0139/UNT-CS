#include <iostream>
using namespace std;

int main()
{
	enum Direction {UP, DOWN, LEFT, RIGHT};
	int x=0, y=0;
	int dir, length;
	bool repeat;
		
	do
	{
		cout<<"Where do you want to move? Enter 0 for UP, 1 for DOWN, 2 for LEFT, 3 for RIGHT, any other integer to Quit:"; cin>>dir;
		
		switch(dir)
		{
			case UP:
				cout<<"By how much?"; cin>>length;
				repeat=true;
				y+=length;
				break;
			
			case DOWN:
				cout<<"By how much?"; cin>>length;
				repeat=true;
				y-=length;
				break;
			
			case LEFT:
				cout<<"By how much?"; cin>>length;
				repeat=true;
				x-=length;
				break;
			
			case RIGHT:
				cout<<"By how much?"; cin>>length;
				repeat=true;
				x+=length;
				break;
			
			default:
				repeat=false;
				cout<<"Quitting."<<endl;
				break;
		}
		if (repeat)
		{
			cout<<"Current Updated position:("<<x<<","<<y<<")"<<endl;
		}
		
	}while(repeat);
	
	cout<<"Final Updated position:("<<x<<","<<y<<")"<<endl;
	return 0;
}