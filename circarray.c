#include<stdio.h>
void cprint(char a[],int n,int ind) {
	char b[(2*n)];
	int i;
	for(i=0;i<n;i++)
		b[i]=b[n+i]=a[i];
}

void print(char a[],int n,int ind) {
	int i;
	for(i=ind;i<n+ind;i++)
		printf("%c\n",a[i%n]);
}

int main() { 
	char a[]={'A','B','C','D','E','F'};
	int n=sizeof(a)/sizeof(a[0]);
	print(a,n,3);
}
