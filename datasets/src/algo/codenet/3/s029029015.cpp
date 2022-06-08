#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
int main(void){
	int n,m,i;
	int bnum[100001]={0};
	int anum[100001]={0};
	int sum=0;
	int j;
	int a[100001];
	int b[100001];
	int c[100001];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	std::sort(a,a+n);
	std::sort(b,b+n);
	std::sort(c,c+n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i] < c[j]){
				bnum[i] += n-j;
				break;
			}
		}
		printf("%d\n",bnum[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i] < b[j]){
				anum[i] += bnum[j];
			}
		}
		printf("%d\n",anum[i]);
	}
	for(i=0;i<n;i++){
		sum += anum[i];
	}
	printf("%d",sum);
	return 0;
}