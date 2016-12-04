#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define diff 0.0001
#define maxit 30
#define f(x) pow(x, 3) + pow(x, 2) - 3*x - 3
#define fd(x) 3*pow(x, 2) + 2*x - 3

int main(void)
{
	int count;
	float x0,xn, fxn;
	cout<<"Please enter the initial value of x: ";
	cin>>x0;
	for(count = 0; count < maxit; count++)
	{
		float z = f(x0), y = fd(x0);
		xn = x0 - z/y;
		if(fabs(xn - x0) < diff)
		{
			cout<<"root = "<<xn<<endl;
			fxn = f(xn);
			cout<<"Functional value: "<<fxn<<endl;
			cout<<"no. of iteraiton: "<<count<<endl;
			exit(0);
		}
		else
		{
			x0 = xn;		
		}
	}
	cout<<"Solution doesn't converse"<<endl;
}
