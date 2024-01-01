// Newton-Raphson Method

#include<stdio.h>
#include<conio.h>
#include<math.h>

double f(double x)
{
	return  4.5 * x - 2 * cos(x);
}

double fder(double x)
{
	return 4.5 + 2 * sin(x);
}

double newtonraphson(double a)
{
	double Tolerance     = 1e-12;
	int    MaxIteration  = 1000;
	int    Counter       = 0;
	double b,c,f0,f1;
				
	do
	{
		f0 = f(a);
		f1 = fder(a);
		
		if(0 == Counter && fabs(f0) < Tolerance)
		{
			return 0;
		}
		
		c = a;
		
		b = a - f0/f1;
		
		a = b;
		
		Counter++;
		
	}while(fabs(a - c) > Tolerance && Counter < MaxIteration );
	
	printf("Number of Iterations: %d\n",Counter);
	return a;	
}

int main()
{
	double a = 0.0; 
	double root = newtonraphson(a);
	
	if(root)
	{
		printf("Root of the equation: %f", root);
	}
	
	else
	{
		printf("No Root Found in the Specified Range");
	}
	
	getch();
}
