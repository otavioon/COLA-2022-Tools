#include<stdio.h>
int main(void){
	int i=1,x,y,temp;
	while(i<=3000){
		scanf("%d %d",&x,&y);
		if (x==0 && y==0)
			break;
		if (x>y){
			temp=x;
			x=y;
			y=temp;
		}
		printf("%d &d\n",x,y);
		i++;
	}
return 0;
}