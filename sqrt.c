#include<stdio.h>
int mysqrt(int x) {
	if(x==0 || x==1)
		return x;
	double start=(double)1,end=(double)x,ans,mid;
	while(start<=end) {
		mid=(start+end)/2;
		if(mid*mid < x+0.000001 && mid*mid > x-0.000001)
			return mid;
		if(mid*mid <x) {
		//	printf("\nmid is %d\n",mid);
			start=mid+1;
			ans=mid;
		}
		else
			end=mid-1;
	}
	return ans;
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
	int x=11;
	printf("\n mysqrt value is %d\n",mysqrt(11));
	finalsqrt(mysqrt(x),x);
}
