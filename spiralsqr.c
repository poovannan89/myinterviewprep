#include<stdio.h>
void main() {
	int **M;
	M=(int**)malloc(5*sizeof(int*));
	int i;
	for(i=0;i<5;i++) {
		M[i]=(int*)malloc(5*sizeof(int));
	}
	int L,R,T,B;
	L=0;
	R=4;
	T=0;
	B=4;
	int dir,k;
	dir=0;
	k=1;
	while(L<=R && T<=B) {
		if(dir==0) {
			for(i=L;i<=R;i++) {
				M[T][i]=k;
			}
			T=T+1;
			dir=1;
		}
		else if(dir==1) {
			for(i=T;i<=B;i++) {
				M[i][R]=k;
			}
			R=R-1;
			dir=2;
		}
		else if(dir==2) {
			for(i=R;i>=L;i--) {
				M[B][i]=k;
			}
			B=B-1;
			dir=3;
		}
		else if(dir==3) {
			for(i=B;i>=T;i--) {
				M[i][L]=k;
			}
			L=L+1;
			dir=0;
			k=k+1;
		}
	}
	printf("\nOutput is\n");
	for(i=0;i<5;i++) {
		for(k=0;k<5;k++) {
			printf("%d\t",M[i][k]);
		}
		printf("\n");
	}
}
