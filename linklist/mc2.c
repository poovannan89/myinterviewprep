#include<stdio.h>
#include<string.h>
 
int main(void)
{
 
 char src[20] ="amlendra";
 char* dst;
 
 memcpy(dst,src,sizeof(src));
 
 return 0;
}
