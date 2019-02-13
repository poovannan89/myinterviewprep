#include<stdio.h>

void* MyMemCpy(void *dest,void *src,size_t len) {
	char *pdest=(char*)dest;
	char *psrc=(char*)src;
	while(len) {
		*(pdest++)=*(psrc++);
		len--;
	}
}

void main() {
	char src[20]="How are you?";
	char dest[20]={0};
	MyMemCpy(dest,src,sizeof(src));
	printf("Dest is %s\n",dest);
}
