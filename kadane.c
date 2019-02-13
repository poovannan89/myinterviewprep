#include<stdio.h>
int max_sum_subarray(int arr[],int n)
{
	int ans=0,sum=0;
	for(i=0;i<n;i++)
	{
		if(sum+arr[i] > 0)
			sum = sum+arr[i];
		else
			sum=0;
		ans = max(ans, sum);
	}
	return ans;
}	



