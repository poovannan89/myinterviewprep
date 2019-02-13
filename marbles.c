#include<stdio.h>
void main() {
	int i,j,k,l;
	int **A;
	A=(int**)malloc(3*sizeof(int*));
	for(i=0;i<3;i++) {
		A[i]=(int*)malloc(3*sizeof(int));
	}
	printf("\nEnter inputs\n");	
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			scanf("%d",&A[i][j]);
		}
	}

	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			if(A[i][j]==1) {
				for(k=i+1;k<3;k++) {
					if(A[k][j]==1) {
						for(l=0;l<3;l++) {
							A[k][l]=-1;
						}
					}
				}
			}
		}
	}

	printf("\nFinal outp\n");
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
