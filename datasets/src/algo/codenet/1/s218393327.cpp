#include<stdio.h>
int main(){
int c[9],i,a=0;
for(i=0;i<9;i++){
scanf("%d",&c[i]);
}
if(c[0]-c[1]==c[3]-c[4]&&c[0]-c[1]==c[6]-c[7]){a++;}
if(c[2]-c[1]==c[5]-c[4]&&c[2]-c[1]==c[8]-c[7]){a++;}
if(c[0]-c[3]==c[1]-c[4]&&c[0]-c[3]==c[2]-c[5]){a++;}
if(c[3]-c[6]==c[4]-c[7]&&c[3]-c[6]==c[5]-c[8]){a++;}
if(a==4)printf("Yes");
else printf("No");
return 0;
}