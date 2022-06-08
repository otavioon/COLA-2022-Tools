#include <stdio.h>

int main(void){
    int ma[3000],mi[3000];
    int a=-1, b=-1, c=0, i;
    while (a != 0 && b != 0){
        scanf("%d %d", &a, &b);
        if (a > b){ma[c]=a,mi[c]=b;}
        else {ma[c]=b,mi[c]=a;}
        c++;
    }
    for(i=0;i<c-1;i++) printf("%d %d\n",mi[i],ma[i]);
}

