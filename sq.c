#include<stdio.h>
double mysqrt(double x) {
	if(x==0 || x==1)
		return x;
	double start=(double)1,end=(double)x,ans,mid=(start+end)/2;
	double ratio = mid/2;
	while(!(mid*mid < x+0.00001 && mid*mid> x-0.00001)) {
		if (mid*mid >x)
			mid -= ratio;
		else 
			mid += ratio;
		ratio /= 2;
	}
	return mid;
}

void finalsqrt(int d,int n) {

	double t,x;
	for(t=0.00001;t<1.0;t+=0.00001) {
		x=(double)d+t;
		if(x*x > (double)n) {
			x=x-0.00001;
			break;
		}
	}
	printf("The sqrt is %.5lf\n",x);	
}


	
int main() {
	double x=2;
	printf("%f\n",mysqrt(x));
}
