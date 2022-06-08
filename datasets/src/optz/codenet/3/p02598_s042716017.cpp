#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
//#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main(){
    long long N,K;
    cin>>N>>K;
    long long A[N],sum=0;
    rep(i,N){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A,A+N);
    long long mi=1,ma=A[N-1];
    while(mi<ma){
        long long mid=(mi+ma)/2;
        long long t=0;
        bool flag=true;
        rep(i,N){
            t+=(A[i]-1)/mid;
            if (t>K){
                flag=false;
                break;
            }
        }
        if (flag){
            ma=mid;
        }
        else{
            mi=mid+1;
        }        
        if (mi+1==ma) break;
    }
    bool flag=true;
    rep(i,N){
        long long t=0;
        t+=(A[i]-1)/ma;
        if (t>K){
            flag=false;
            break;
        }
    }
    if (flag) cout<<mi<<endl;
    else cout<<ma<<endl;
    return 0;
}
