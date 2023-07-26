#include <iostream>
using namespace std;

void getArray(double array[], int size)
{
	for (int i=0;i<size;++i)
	{
		//cin>>array[i];
		//fin>>array[i];
		array[i]=static_cast<double>(rand()%101+100);
		
	}
	
	
}

void sortArray(double array[], int size)
{
	for (int i=0;i<size;++i)
	{
		for (int j=i+1; j<size;++i)
		{
			if (array[i]>array[j])
			{
				double temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	
}

void showArray(double array[], int size)
{
	for (int i=0;i<size;++i)
	{
		cout<<array[i]<<endl;
	}
}


void writeArray(double array[], int size, ofstream& fout)
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2); //or setprecision
	for (int i=0;i<size;++i)
	{
		fout<</*setprecision(somevalue)*/array[i]<<endl;
	}
}

int main()
{
	double *array;
	
	int size;
	//cin>>size;
	//fin>>size;
	size=rand()%6+5;
	
	array=new double[size];
	
	getArray(array, size);
	sortArray(array, size);
	showArray(array, size);
	
	ofstream fout;
	string file;
	cin>>file;
	fout.open(file);
	// check fail
	writeArray(array, size, fout);
	fout.close();
	
	delete [] array;
	
	
	return 0;
}
