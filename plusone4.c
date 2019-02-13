#include<stdio.h>
#include<math.h>
int* plusOne(int* A, int n1, int *len1) {
	int *B;
	int i,n2,ii,ninec,newn1,j,k,flg;
	i=0;
	ninec=0;
	while(A[i]==0 && i<n1-1)
                i++;
	newn1=n1-i;
	for(j=i;j<n1;j++)
	{
		if(A[j]==9)
			ninec++;
	}
	if(ninec==newn1)
		n2=newn1+1;
	else
		n2=newn1;
	*len1=n2;
	B=(int*)malloc(n2*sizeof(int));
	j=n1-1;
	k=n2-1;
	flg=1;
	while(j>=i)
	{
		if(A[j]==9 && flg==1)
		{
			B[k]=0;
			flg=1;
		}
		else
		{
			if(flg==1)
				B[k]=A[j]+1;
			else if(j==n1-1)
                                B[k]=A[j]+1;
                        else
			{
                               	B[k]=A[j];
			}
			flg=0;
		}
		j--;
		k--;
	}
	if(flg==1)
		B[k]=1;
	printf("\nfter while\n");
	/*for(i=0;i<n2;i++)
		printf("%d\t",B[i]);*/
	return B;
}

void main()
{
	int *B;
	int *A;
	int n1,i,len1;
	n1=4;
	A=(int*)malloc(n1*sizeof(int));
	printf("\nEnter numbers\n");
	for(i=0;i<n1;i++)
		scanf("%d",&A[i]);
	B=plusOne(A,n1,&len1);
	for(i=0;i<len1;i++)
                printf("%d\t",B[i]);
}
