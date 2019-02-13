#include<stdio.h>

int circbinsearch(int a[],int n,int el) {
	int low,high,mid;
	low=0;
	high=n-1;
	printf("\ninside func n is %d\n",n);
	while(low<=high) {
		mid=(low+high)/2;
		if(el==a[mid])
			return mid;
		if(a[mid]<=a[high]) {
			if((el > a[mid]) && (el <= a[high])) {
				low=mid+1;
			}
			else
				high=mid-1;
		}
		else {
			if((el >= a[low]) && (el < a[mid]))
				high=mid-1;
			else
				low=mid+1;
		}
	}
	return -1;
}


void main() {
        int a[]={6,7,8,9,3,4,5};
        int n;
        n=sizeof(a)/sizeof(a[0]);
	printf("\nbefore calling func\n");
        printf("pos is %d\n",circbinsearch(a,n,8));
}
