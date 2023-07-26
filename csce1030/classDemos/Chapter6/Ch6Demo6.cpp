#include <iostream>
using namespace std;

void isPassing (int score, int threshold)
{
	if (score>=threshold)
	{
		cout<<"Passing."<<endl;
	}
	else
	{
		cout<<"Not passing."<<endl;
	}
	
	
}

int main()
{
	int score=40, threshold=60;
	
	isPassing(score, threshold);
	//isPassing(threshold, score); //logical error
	
	//Passing by value
	isPassing(50, 80);
	
	
	return 0;
}





