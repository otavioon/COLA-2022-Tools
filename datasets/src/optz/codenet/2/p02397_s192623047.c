#include <stdio.h>
  
int main(void){
int number[10000][2],x,y,i=0,n;
do{
scanf("%d %d",&x,&y);
}while(!(x>=0 && x<=10000 && y>=0 && y<=10000));
if(x!=0 && y!=0){
	do{
		i++;
		if(x>=y){
			number[i][0]=y;
			number[i][1]=x;
		}else{
			number[i][0]=x;
			number[i][1]=y;
		}
		do{
			scanf("%d %d",&x,&y);
		}while(!(x>=0 && x<=10000 && y>=0 && y<=10000));
	} while(x!=0 && y!=0 && i<=3000);
}
n=i;
for(i=1;i<=n;i++){
printf("%d %d\n",number[i][0],number[i][1]);
}
return 0;
}