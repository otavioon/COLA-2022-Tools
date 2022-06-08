#include<stdio.h>
int main(){
int n,a,b,SUMNUM;
char NUM[a],MAXNUM,MINNUM;
scanf("%d",&n);
scanf("%d",&b);
MAXNUM=b;
MINNUM=b;
SUMNUM=b;
for(a=1;a<n;a++){
scanf("%d",&b);
NUM[a]=b;

if(MAXNUM<NUM[a]){
MAXNUM=NUM[a];
}
if(MINNUM>NUM[a]){
MINNUM=NUM[a];
}
SUMNUM=SUMNUM+NUM[a];
}
printf("%d %d %d\n",MINNUM,MAXNUM,SUMNUM);
	return 0;
}