#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n,i,x=0,y=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		if(a[i]==0&&b[i]==1){
			x++;
		}else if(a[i]==0&&b[i]==2){
			y++;
		}else if(a[i]==1&&b[i]==0){
			y++;
		}else if(a[i]==1&&b[i]==2){
			x++;
		}else if(a[i]==2&&b[i]==0){
			x++;
		}else if(a[i]==2&&b[i]==1){
			y++;
		}
	}
	if(x>y){
		printf("A");
	}else if(x<y){
		printf("B");
	}else if(x==y){
		printf("Tie");
	}		
	return 0;
}