#include <stdio.h>

int main()
{

long int a[10000];
long int max, min, sum;
int i;

for(i=0;i++;i<10000){
scanf("%ld", &a[i]);
}

max = a[0];
min = a[0];
sum = 0;

for(i=0;i++;i<10000){
sum += a[i];
if(max < a[i]){
max = a[i];
}
else if(min > a[i]){
min = a[i]; 
}
}
printf("%ld %ld %ld\n", min, max, sum);
}