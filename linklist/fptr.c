#include<stdio.h>
int Add(int a,int b) {
	return a+b;
}

int main() {
	int (*Addptr)(int,int);
	Addptr=Add;
	printf("Ans is %d\n",(*Addptr)(5,10));
	return 1;
}
