#include <iostream>
using namespace std;

int main()
{
	enum Direction {UP, DOWN, LEFT, RIGHT};
	int x=0, y=0;
	int dir, length;
	char answer;	
	do
	{
		cout<<"Where do you want to move? Enter 0 for UP, 1 for DOWN, 2 for LEFT, 3 for RIGHT:"; cin>>dir;
		cout<<"By how much?"; cin>>length;
		switch(dir)
		{
			case UP:
				y+=length;
				break;
			
			case DOWN:
				y-=length;
				break;
			
			case LEFT:
				x-=length;
				break;
			
			case RIGHT:
				x+=length;
				break;
			
			default:
				cout<<"Wrong choice."<<endl;
				break;
		}
		cout<<"Current Updated position:("<<x<<","<<y<<")"<<endl;
		cout<<"Do you want to move again? Y/N:"; cin>>answer;
	}while(toupper(answer)=='Y');
	
	cout<<"Final Updated position:("<<x<<","<<y<<")"<<endl;
	return 0;
}