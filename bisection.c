#include <stdio.h>
#include <math.h>

#define PI 3.1415926536
#define f(x) sin(x*PI/180)-1/x
#define end 1.000


float check_br(float, float);
int main(void)
{
	float a, b;
	printf("Please enter the starting two values: ");
	scanf("%f %f", &a, &b);
	float root = check_br(a, b);
	printf("Return: %f\t", root);
	if(roundf(root) == 0)
	{
		printf("The input doesn't match the bracket\n");
		return 1;
	}
	else
	{
		printf("The root of the given equation is: %f\n", root);
		printf("The functional value is: %f", f(root));
	}
	return 0;
}

float check_br(float a, float b)
{
	int count = 0;
	float mid = 1;	
	float f1 = f(a);
	float f2 = f(b);
	if(f1 * f2 > 0)
	{
		return 0;
	}
	else
	{
		do
		{
			mid = (a + b)/2.0;
			printf("mid: %f", mid);
			if(f(mid) < 0)
			{
				a = mid;
			}
			else
			{
				b = mid;
			}
			count++;
			if(roundf(fabs(mid - (a+b)/2.0)) * 10000 == end)
			{
				return mid;
			}
		}while(count != 50);
	}
	printf("The number of iteration is: %d", count);
	return mid;
}
