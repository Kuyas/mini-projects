// C++ Program to find root of a function, f(x)
#include<bits/stdc++.h>
using namespace std;

const int MAX_ITERATIONS = 100000;

// Function to calculate f(x)
double f(double x)
{
	// Taking f(x) = x ^ 3 + 2x ^ 2 + 10x - 20
	return 1*pow(x, 3) - 4*x + 1;
}

void Muller(double x2, double x1, double x0)
{
	int i;
	double res;

	ofstream cout;

	cout.open("muller.txt", ios::app);

	for (i = 0;i <5;++i)
	{
		// Calculating various constants required
		// to calculate x3

		cout<<"x1 :"<<x1<<endl;
		cout<<"x0 :"<<x0<<endl;
		cout<<"x2 :"<<x2<<endl;
		double f2 = f(x2);
		double f1 = f(x1);
		double f0 = f(x0);
		double d1 = f1 - f0;
		double d2 = f2 - f0;
		double h1 = x1 - x0;
		double h2 = x0 - x2;
		double v = h2/h1;
		double c = f0;
		double a = (v*f1 - f0*(1+v) + f2)/(v*pow(h1,2)*(1+v));
		double b =  (f1 - f0 - a*pow(h1,2))/h1;
		double x;
		if(b>=0){
             x = ((-2*c) / (b + abs(sqrt(b*b-4*a*c))));
		}else if(b<=0){
		     x = ((-2*c) / (b-abs(sqrt(b*b-4*a*c))));

		}
		//double y = ((-2*a0) / (a1-abs(sqrt(a1*a1-4*a0*a2))));

		// Taking the root which is closer to x2
		res = x + x0;
		double xr = res;

		// checking for resemblance of x3 with x2 till
		// two decimal places
//		if (m == n)
// 			break;
       // cout<<a<<b<<endl;
       if(xr > x0){

            x2 = x0;
            x0 = xr;

       }else {

           x1 = x0;
           x0 = xr;


       }

		//cout<<a<<b<<endl;

		if (i > MAX_ITERATIONS)
		{
			cout << "Root cannot be found using"
				<< " Muller's method";
// 			break;
		}



		cout<<"ITERATION "<<i+1<<endl;
		cout<<"f1: "<<f1<<endl;
		cout<<"f2: "<<f2<<endl;
		cout<<"f0: "<<f0<<endl;
		cout<<"h1: "<<h1<<endl;
		cout<<"h2: "<<h2<<endl;
		cout<<"v: "<<v<<endl;
		cout<<"a: "<<a<<endl;
		cout<<"b: "<<b<<endl;
		cout<<"c: "<<c<<endl;
		//cout<<a<<endl<<b<<endl<<c<<endl;
		cout<<"root: "<<xr<<endl;


	}
	if (i <= MAX_ITERATIONS)
		cout << "The value of the root is " << res;

		cout.close();

}

// Driver main function
int main()
{


	double a = -3, b = -2, c = -2.5;
	Muller(a, b, c);
	return 0;

}

