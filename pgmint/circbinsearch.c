#include<stdio.h>
int circbinsearch(int a[],int n,int x) {
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high) {
		mid=(low+high)/2;
		if(x==a[mid])
			return mid;
		else {
			if(a[mid]<=a[high]) {
				if(x>a[mid] && x<=a[high]) {
					low=mid+1;
				}
				else 
					high=mid-1;
			}
			else {
				if(x>=a[low] && x<a[mid]) {
					high=mid-1;
				}
				else 
					low=mid+1;
			}
		}
	}
	return -1;
}

void main() {
	int a[]={6,7,8,9,3,4,5};
	int n;
	n=sizeof(a)/sizeof(a[0]);
	printf("pos is %d\n",circbinsearch(a,n,12));
}
