#include<iostream>
#include<cstdio>
int c[4][4];
int main() {
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%d",c[i]+j);
    bool ok=true;
    int a=c[1][2]-c[1][1],b=c[1][3]-c[1][2];
    if(c[2][2]-c[2][1]!=a||c[2][3]-c[2][2]!=b||c[3][2]-c[3][1]!=a||c[3][3]-c[3][2]!=b) ok=false;
    a=c[2][1]-c[1][1],b=c[3][1]-c[2][1];
    if(c[2][2]-c[1][2]!=a||c[3][2]-c[2][2]!=b||c[2][3]-c[1][3]!=a||c[3][3]-c[2][3]!=b) ok=false;
    printf("%s\n",ok?"Yes":"No");
    return 0;
}
