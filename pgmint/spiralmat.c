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

