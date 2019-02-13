int binarysearchoccur(int a[],int n,int el,int oflg) {
	int low,high,mid;
	int result=-1;
	low=0;
	high=n-1;
	while(low<=high) {
		mid=(low+high)/2;
		if(el==a[mid]) {
			result=mid;
			if(oflg==0)
				high=mid-1;
			else
				low=mid+1;
		}
		else if(a[mid]>el) {
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return result;
}
	



void main() {
        int a[]={2,4,10,10,10,18,20};
        int n;
        n=sizeof(a)/sizeof(a[0]);
        printf("pos is %d\n",binarysearchoccur(a,n,10,1));
}
