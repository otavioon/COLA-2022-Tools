#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char subn[10],input[10000];
gets(subn);
int n = atoi(subn);
gets(input);
int i=0,j=0;
int num[n];
char media[10],submedia[2];
for(i;i<n;i++){
media[0]='\0';
while(input[j] != ' '&&input[j] != '\0'){
submedia[0]=input[j];
submedia[1]='\0';
strcat(media,submedia);
j++;
}
j++;
num[i]=atoi(media);
}
int min=num[0],max=num[0];
long long sum=num[0];
for(i=1;i<=n-1;i++){
sum+=num[i];
if(num[i]>max){
max=num[i];
}
if(num[i]<min){
min=num[i];
}
}
printf("%d %d %lld\n",min,max,sum);
return NULL;
}