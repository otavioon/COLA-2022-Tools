#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
#define ASCII 100
#define MAX_N 100
#define MAX_N 100
#define L 100
#define MAX 100
#define ASC 100
#define null 0
#define Len 100
#define M 100
#define SUM 100
#define NUMBER 100
#define SIZE 100
#define N 100
#define Max 100
#define X 100
#define Y 100
#define A 100
#define MAXN 100
#define MAXSIZE 100
int main(){
    int a[MAX];
    int n,k,i,j,s;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    s=a[1]+a[2];
    for(i=0;i<n;i++){
        if(s==k){
            break;
        }
        else{
        for(j=0;j<n;j++){
           s=a[i]+a[j];
           if(s==k)
           break;
           else
           s=s;
        }}
    }
    if(s==k){
        printf("yes");
    }
    else
    printf("no");
    return 0;
}
