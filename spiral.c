#include<stdio.h>
int* spiralOrder(int** A, int n11, int n12, int *len1) {
    int T=0,B=n11-1,L=0,R=n12-1;
    int dir,k,i;
    int *BB;
    k=0;
    dir=0;
    int len2;
    //len2=(int*)malloc(1*sizeof(int));
    len2=n11*n12;	
    *len1=len2;	
    BB=(int*)calloc(len2,sizeof(int));
    while(L<=R && T<=B)
    {
        if(dir==0)
        {
            for(i=L;i<=R;i++)
            {
                BB[k++]=A[T][i];
            }
            T++;
            dir=1;
        }
        else if(dir==1)
        {
            for(i=T;i<=B;i++)
            {
                BB[k++]=A[i][R];
            }
            R--;
            dir=2;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--)
            {
                BB[k++]=A[B][i];
            }
            B--;
            dir=3;
        }
	else if(dir==3)
        {
            for(i=B;i>=T;i--)
            {
                BB[k++]=A[i][L];
            }
            L++;
            dir=0;
        }
    }
    return BB;
}
void main()
{
	int *B;
	int i,n11,n12,j;
	int len1;
	n11=1;
	n12=1;
	printf("\nInside main");
	int **A=(int**)malloc(n11* sizeof(int*));
	for(i=0; i<n11;i++)
		A[i]=(int*)malloc(n12 *sizeof(int));
	printf("\nAfter 2d malloc\n");	
	for(i=0;i<n11;i++)
	{
		for(j=0;j<n12;j++)
		{
			A[i][j]=1;
		}
	}
	printf("\nAfter init array\n");
	B=spiralOrder(A,n11,n12,&len1);
	printf("\nLen1 is %d\n",len1);
	for(i=0;i<len1;i++)
		printf("%d\t",B[i]);
}
