#include<stdio.h>
int* plusOne(int* A, int n1, int *len1) {
    
    int *B;
    int i,cnt,j;
    i=0;
    while(A[i]==0)
        i++;
    cnt=n1-i;
    B=(int*)malloc(cnt*sizeof(int));
    j=0;
    while(i<n1)
    {
        if(i==n1-1)
            B[j]=A[i]+1;
        else
            B[j]=A[i];
        j++;
        i++;
    }
    *len1=cnt;
    return B;	    
}

void main()
{
	int *B;
	int *A;
	int n1,i,len1;
	n1=5;
	A=(int*)malloc(n1*sizeof(int));
	printf("\nEnter 5 numbers\n");
	for(i=0;i<n1;i++)
		scanf("%d",&A[i]);
	B=plusOne(A,n1,&len1);
	for(i=0;i<len1;i++)
                printf("%d\t",B[i]);
}
