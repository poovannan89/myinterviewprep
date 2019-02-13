#include<stdio.h>
int max_subarray_sum(int arr[],int n)
{
	int m,left_mss,right_mss,i;
	int leftsum,rightsum,sum,ans;
	leftsum=INT_MIN;
	rightsum=INT_MIN;
	sum=0;
	if(n==1)
		return arr[0];
	m=n/2;
	left_mss=max_subarray_sum(arr,m);
	right_mss=max_subarry_sum(arr+m,n-m);
	for(i=m;i<n;i++)
	{
		sum = sum + arr[i];
		rightsum = max(rightsum,sum);
	}
	sum =0 ;
	for(i=m-1;i>=0;i--)
	{
		sum = sum + arr[i];
		leftsum = max(leftsum,sum);
	}	
	ans = max(left_mss,right_mss);
	return max(ans,leftsum+rightsum);
}
