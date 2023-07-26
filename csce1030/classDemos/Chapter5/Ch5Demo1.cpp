//array: a collection of data items/variables of the same data type
#include <iostream>
using namespace std;

int main()
{
	/*
	//this approach is not scalable
	int score1, score2, score3;
	cin>>score1>>score2>>score3;
	double sum=score1+score2+score3;
	cout<<"average="<<sum/3<<endl;
	
	
	//scalable, but does not store data for further processing
	int count=3;
	double sum=0;
	for (int i=0; i<count; ++i)
	{
		cin>>score;
		sum+=score;
	}
	cout<<"average="<<sum/count<<endl;
	*/
	
	int score[5]; //a collection of 5 integer variables
	//data type: int, name:score, size:5
	
	
	score[0]=-35; //first variable/member
	cout<<"Enter an integer:"; cin>>score[1]; //second variable/mmeber
	score[2]=3*score[0]+5*score[1];
	if (score[2]>0)
	{
		score[3]=1;
	}
	else
	{
		score[3]=0;
	}
	score[4]=12 //last variable/member
	
	//score[5]=15; //outside the range, maximum is size-1
	
	double array[10]; //a collection of 10 double variables
	
	return 0;
}






