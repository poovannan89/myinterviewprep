#include<stdio.h>
int main()
{
	int A;
	int **B;
	int i,j;
	scanf("%d",&A);
	B=(int**)malloc(A*sizeof(int*));
	for(i=0;i<A;i++)
		B[i]=(int*)malloc((i+1)*sizeof(int));
	B[0][0]=1;
        for(i=1;i<A;i++)
        {
                for(j=0;j<i+1;j++)
                {
                if(j-1<0)
                        B[i][j]=B[i-1][j];
                else if(j==i)
                        B[i][j]=B[i-1][j-1];
                else
                        B[i][j]=B[i-1][j]+B[i-1][j-1];
                }
        }
	printf("Output\n");
	for(i=0;i<A;i++)
	{
		for(j=0;j<i+1;j++)
		{
			printf("%d\t",B[i][j]);
		}
		printf("\n");
	}
	return 0;
}
