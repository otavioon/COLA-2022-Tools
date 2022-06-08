#include <stdio.h>

int main()
{

int i,j;
scanf("%d", &j);

long int a[j];
for(i=0;i<j;i++)
a[i] = 0;

long int min, max;
long int sum = 0;

for(i=0;i++;i<j){
scanf("%ld", &a[i]);
}

max = a[0];
min = a[0];

for(i=0;i++;i<j){
sum += a[i];
if(max < a[i]){
max = a[i];
}
else if(min > a[i]){
min = a[i]; 
}
}
printf("%ld %ld %ld", min, max, sum);
}