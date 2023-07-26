#include <stdio.h>

int main()
{
	int my_int=25;
	char my_char='+';
	double my_dbl=2.5896;
	float my_flt=-3.5896;
	//C++ Method
	/*
	cout<<"Hello world!!!"<<endl;
	
	cout<<"my_int="<<my_int<<endl;
	cout<<"my_char="<<my_char<<"\tmy_dbl="<<my_dbl<<endl;
	cout<<"my_flt="<<my_flt<<endl;*/
	
	
	//C-method
	printf("Hello world!!!\n");
	printf("my_int=%d\n",my_int);
	printf("my_char=%c\tmy_dbl=%lf\n",my_char,my_dbl);
	printf("my_flt=%f\n", my_flt);
	
	
	//C++ method
	/*
	cout<<"Enter integer:";
	cin>>my_int;
	cout<<"Enter character and double:";
	cin>>my_char>>my_dbl;
	cout<<"Enter float:";
	cin>>my_flt;
	cout<<"my_int="<<my_int<<endl;
	cout<<"my_char="<<my_char<<"\tmy_dbl="<<my_dbl<<endl;
	cout<<"my_flt="<<my_flt<<endl;*/
	
	//C-method
	/
	printf("Enter character:");
	scanf("%c",&my_char);
	
	printf("Enter integer and double:");
	scanf("%d %lf",&my_int, &my_dbl);
	
	printf("Enter float:");
	scanf("%f", &my_flt);
	
	printf("my_int=%d\n",my_int);
	printf("my_char=%c\tmy_dbl=%lf\n",my_char,my_dbl);
	printf("my_flt=%f\n", my_flt);
	
	my_flt=2.5879631;
	printf("Output=%e\n", my_flt);
	
	
	
	
	return 0;
}