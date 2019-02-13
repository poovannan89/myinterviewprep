#include<stdio.h>
#include<math.h>
int* plusOne(int* A, int n1, int *len1) {
	int *B;
	int i,n2,ii;
	unsigned long long int sum,tres,j,t;
	i=0;
	while(A[i]==0 && i<n1-1)
		i++;
	ii=n1-1;
	j=0;
	sum=0;
	while(ii>=i)
	{
		if(j==0)
			sum=sum+A[ii];
		else
		{
			t=A[ii];	
			tres=pow(10,j);
			t=t*tres;
			sum=sum+t;
		}
		ii--;
		j++;
	}
	printf("Number is %d\n",sum);				  
	sum=sum+1;
	tres=sum;
	n2=0;
	while(sum>0)
	{
		j=sum%10;
		sum=sum/10;
		n2++;
	}
	printf("No of digits is %d\n",n2);
	*len1=n2;
	B=(int*)malloc(n2*sizeof(int));
	sum=tres;
	ii=n2-1;
	while(sum>0)
	{
		j=sum%10;
		B[ii--]=j;
		sum=sum/10;
	}
	printf("\nAfter while\n");
	return B;
}

void main()
{
	int *B;
	int *A;
	int n1,i,len1;
	n1=12;
	printf("Szie of int is %d\n",sizeof(int));
	A=(int*)malloc(n1*sizeof(int));
	printf("\nEnter numbers\n");
	for(i=0;i<n1;i++)
		scanf("%d",&A[i]);
	B=plusOne(A,n1,&len1);
	for(i=0;i<len1;i++)
                printf("%d\t",B[i]);
}
