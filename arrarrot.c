#include<stdio.h>
int gcd(int a,int b) {
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

void leftrotate(int arr[],int d,int n) {
	int i,j,k,tmp;
	for(i=0;i<gcd(d,n);i++) {
		tmp=arr[i];
		j=i;	
		while(1) {
			k=j+d;
			if(k>=n)
				k=k-n;
			if(k==i)
				break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=tmp;
	}
}	

