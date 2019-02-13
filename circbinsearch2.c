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

int findPivot(int a[],int low,int high) {
	if(high<low)
		return -1;
	if(low==high)
		return low;
	int mid;
	mid=(low+high)/2;
	if(mid<high && a[mid]>a[mid+1])
		return mid;
	if(low<mid && a[mid]<a[mid-1])
		return mid-1;
	if(a[high]>a[mid])
		return findPivot(a,low,mid-1);
	return findPivot(a,mid+1,high);

}

void main() {
	int a[]={5,6,7,8,9,10,1,2,3};
	int n;
	n=sizeof(a)/sizeof(a[0]);
	printf("pos is %d\n",findPivot(a,0,n-1));
}
