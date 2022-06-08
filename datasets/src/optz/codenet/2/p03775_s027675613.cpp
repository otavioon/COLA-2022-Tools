#include <bits/stdc++.h>
using namespace std;
int fun(int n){
    int a=0,b,c;
    while(n>0){
        a++;
        n = n/10;
    }
    return a;
}
int main(){
    long long int p,q;
    int a,b,c,i,n;
    cin>>q;
    for(i = sqrt(q);i >= 1;i++){
        if(q%i==0){

            break;
        }
    }
    a = q/i;
    b = fun(a);
    c = fun(i);
    n = b;
    if(n < c){
        n = c;
    }
    cout<<n;
}
