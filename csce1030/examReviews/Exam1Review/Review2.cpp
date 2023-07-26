struct Test
{
	string fname;
	string lname;
	int age;
	//int score[5];
	
	//int* games;
};

void findYoungest(Test t[])
{
	int min_age=t[0].age;
	string min_name=t[0].fname+" "+t[0].lname;
	for (int i=1;i<4;++i)
	{
		if (min_age > t[i].age)
		{
			min_age=t[i].age;
			min_name=t[i].fname+" "+t[i].lname;
		}
		
	}
	cout<<min_name<<" is the youngest one."<<endl;
	
}

void findYoungest2(Test t[], int sz)
{
	int min_age=t[0].age;
	string min_name=t[0].fname+" "+t[0].lname;
	for (int i=1;i<sz;++i)
	{
		if (min_age > t[i].age)
		{
			min_age=t[i].age;
			min_name=t[i].fname+" "+t[i].lname;
		}
		
	}
	cout<<min_name<<" is the youngest one."<<endl;
	
}

int main()
{
	Test t;
	cin>>t.fname>>t.lname; //name
	cin>>t.age; //age
	
	//if there is a dynamic array member
	//t.games=new int[some_size];
	//delete t.games;
	
	//t[i].games=new int[some_size];
	//delete [] t[i].games
	
	
	Test t2[SIZE];
	for (int i=0;i<SIZE;++i)
	{
		cin>>t2[i].fname>>t2[i].lname; //name
		cin>>t2[i].age; //age
		/*
		for (int j=0;j<5;++j)
		{
			cin>>t2[i].score[j];
		}
		*/
	}
	
	
	Test t3[SIZE];
	ifstream fin;
	fin.open("strcuture.dat");
	//fail check
	for (int i=0;i<4;++i)
	{
		fin>>t3[i].fname>>t3[i].lname; //name
		fin>>t3[i].age; //age
	}
	
	fin.close();
	
	
	findYoungest(t3);
	
	
	Test* t4;
	t4=new Test;
	cin>>t4->fname>>t4->lname; //name
	cin>>t4->age; //age
	delete t4;
	
	Test* t5;
	int sz;
	cin>>sz;
	t5=new Test[sz];
	for (int i=0;i<sz;++i)
	{
		cin>>t5[i].fname>>t5[i].lname; //name
		cin>>t5[i].age; //age
		
	}
	findYoungest2(t5, sz);
	delete [] t5;
	
	
	
	return 0;
}