#include<stdio.h>
void A() {
	printf("\nIam func A\n");
}
void B(void (*ptr)()) {
	(*ptr)();
}

int main() {
	void (*ptr)()=&A;
	B(ptr);
}
