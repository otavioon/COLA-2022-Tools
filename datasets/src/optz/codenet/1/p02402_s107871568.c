#include <stdio.h>
#include <math.h>
int main(void){
	int n;
	int sum;
	scanf("%d\n",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i;i<n;i++){
		sum=sum+a[i];
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("%d %d %d\n",a[0],a[n-1],sum );
	return 0;
}