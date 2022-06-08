#include<stdio.h>
int main(void){
int x,y,n=0;

while(1){
scanf("%d %d",&x,&y);
if(x==0||y==0) break;
if(x>y){
n=x;
x=y;
y=n;
}
else{
    x=x;
    y=y;
}
printf("%d %d\n",x,y);


}
return(0);
}
