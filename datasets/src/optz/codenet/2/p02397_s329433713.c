#include<stdio.h>
int main(){
int i,j,temp;
int x[10000];
int y[10000];

for(i=0; i<10000; i++){
   scanf("%d%d", x[i], y[i]);
if(x[i]>y[i]){
 temp = x[i];
 x[i] = y[i];
 y[i] = temp;
}

if(x[i]==0 && y[i]==0){
  break;
 }
}

for(j=0; j<i; j++){
 printf("%d %d\n", x[j], y[j]);
}

return 0;

}  