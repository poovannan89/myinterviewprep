#include<stdio.h>
int binarySearch(int a[],int f,int l,int ele) {
	int mid;
	if(f>l)
		return -1;
	else {
		mid=(f+l)/2;
		if(a[mid]==ele)
			return mid;
		else if(a[mid]>ele) {
			return binarySearch(a,f,mid-1,ele);
		}
		else {
			return binarySearch(a,mid+1,l,ele);
		}
	}
}

int binarySearch2(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle itself 
        if (arr[mid] == x)  return mid; 
  
        // If element is smaller than mid, then it can only be present 
        // in left subarray 
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
  
        // Else the element can only be present in right subarray 
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not present in array 
   return -1; 
} 

/*
int binarySearchIt(int arr[], int l, int r, int x) 
{ 
  while (l <= r) 
  { 
    int m = l + (r-l)/2; 
  
    // Check if x is present at mid 
    if (arr[m] == x)  
        return m;   
  
    // If x greater, ignore left half   
    if (arr[m] < x)  
        l = m + 1;  
  
    // If x is smaller, ignore right half  
    else 
         r = m - 1;  
  } 
  
  // if we reach here, then element was not present 
  return -1;  
} */

void main()
{
	int a[]={7,10,12,16,18};
	printf("Element index is %d\n",binarySearch(a,0,4,90));
}	
