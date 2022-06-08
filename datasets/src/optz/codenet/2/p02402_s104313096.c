#include<stdio.h>

int main(void){

int n;

int a[10000];

int max, min;

long int sum = 0;

scanf("%d", &n);

int i;

for(i = 0; i<n; i++) {

scanf("%d", a[i]);

}


  min = a[0];

max = a[0];

for(i = 0; i < n; i++) {

if(a[i] < min) {

min = a[i];

} else if(a[i] > max) {

max = a[i];

}

sum += a[i];

}

printf("%d %d %d\n", min, max, sum);

return 0;

}