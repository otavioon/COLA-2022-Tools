#include <stdio.h>
#include <algorithm>
#include <functional>
int main(void){
	int N;
	int a[3][3];
	int sum=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			sum += a[i][j];
		}
	}
	if(sum % 3 != 0){
		printf("No");
	}else{
		printf("Yes");
	}
	return 0;
}