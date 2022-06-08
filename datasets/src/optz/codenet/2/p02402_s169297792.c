#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *arr, x, i;
    int max, min;
    long sum;
	
	scanf("%d", &x);
	arr=(int*)malloc(sizeof(int)*x);
	for(i=0;i<x;i++)
	  scanf("%d", &arr[i]);
	
		max=arr[0];
		min=arr[0];
		sum=arr[0];
		
	for(i=0; i<x-1; i++)
	{
         if(arr[i]<arr[i+1] && max<arr[i+1])
        max=arr[i+1];
      	
      	 if(arr[i]>arr[i+1] && min>arr[i+1])
      	min=arr[i+1];
      	
      	sum+=arr[i+1];
	}
	
	printf("%d %d %li\n", min, max, sum);
	free(arr);
	
	return 0;
}