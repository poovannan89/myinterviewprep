void memcpy(void *src,void *dst,size_t len) {
	char *psrc=(char*)src;
	char *pdst=(char)dst;
	while(len--)	
		*psrc++=*pdst++;

}

void memcpy(void* src, void* dst, size_t len) 
{ 
/* Copy whatever can be copied as integers */ 

size_t nTimes = len/sizeof(int); 
int* pIntSrc = (int*) src; 
int* pIntDst = (int*) dst; 

while( nTimes-- ) 
*pIntSrc++ = *pIntDst++; 

/* copy the remainder */ 
nTimes = len % sizeof(int); 
char* pCharSrc = (char*) pIntSrc; 
char* pCharDst = (char*) pIntDst; 

while( nTimes-- ) 
*pCharSrc++ = *pCharDst++; 

/* Done */ 
}
