#include <stdio.h>

int x,y;
int i=1;

main(){
	while(i<=3000){
		scanf("%d%d",&x,&y);
		if(x != 0 && y != 0 && x <= 0 && y <= 10000){
			if(x<y){
				printf("%d %d\n",x,y);
			}else{
				printf("%d %d\n",y,x);
			}
		}else{
			break;
		}
		i++;
	}
	return 0;
}