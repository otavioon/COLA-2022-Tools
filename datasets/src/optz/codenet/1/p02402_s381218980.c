#include <stdio.h>
#include <string.h>

int min(int a[]);
int max(int a[]);
int sum(int a[]);


int main(void){
	int n;
	int a[10000];
	int i;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("%d %d %d",min(a),max(a),sum(a));

	return 0;
}
int max(int a[]){
	int i;
	int max;

	max=0;
	for(i=0;i<=sizeof(a);i++){
		if(max < a[i])max = a[i];
	}
	return max;
}

int min(int a[]){
	int i;
	int min;

	min=a[0];
	for(i=1;i<=sizeof(a);i++){
		if(min > a[i])min = a[i];
	}
	return min;
}

int sum(int a[]){
	int i;
	int sum=0;

	for(i=0;i<=sizeof(a);i++){
		sum += a[i];
	}
	return sum;
}