//Find the sum of a list of 10 numbers
/*Algorithm:
1. Get number from user.
2. Add the number to the previously computed sum
3. Have I processed 10 numbers?
	Yes: Sum computation is complete, move to next step
	No: Go back to Step 1
4. Give the sum to the user

*/

#include <iostream>
using namespace std;

int main()
{
	int count=0;
	int number;
	int sum=0;
	
	while(count<10)
	{
		cout<<"Enter number #"<<count+1<<":";
		cin>>number;
		sum=sum+number;
		count+=1;
	}
	cout<<"Sum="<<sum<<endl;
	
	return 0;
}