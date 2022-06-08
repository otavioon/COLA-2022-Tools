#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

double a[4][4];

int main(){
    for(ll i=1; i<=3; i++){
        for(ll j=1; j<=3; j++) scanf("%lf",&a[i][j]);
    }
    if(a[1][2]+a[2][3]+a[3][1]+a[1][3]+a[2][1]+a[3][2]==(a[1][1]+a[2][2]+a[3][3])*2) printf("Yes");
    else printf("No");
    return 0;
}