#include<stdio.h>

int rotateCnt(int a[],int n) {
	int low,high,mid;
	int next,prev;
	low=0;
	high=n-1;
	while(low<=high) {
		if(a[low]<=a[high])
			return low;
		else {
			mid=(low+((high-low))/2);
			next=(mid+1)%n;
			prev=(mid-1+n)%n;
			if(a[mid] <= a[next] && a[mid] <= a[prev])
				return mid;
			else if(a[high] >= a[mid])
				high=mid-1;
			else if(a[low] <= a[mid])		
				low=mid+1;
		}
	}
	return -1;
}


void main() {
       	// int a[]={6,7,8,9,3,4,5};
	int a[]={5,8,11,12,2,3};
        int n;
        n=sizeof(a)/sizeof(a[0]);
        printf("pos is %d\n",(rotateCnt(a,n)));
}

