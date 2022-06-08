#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N;
    cin>>N;
    long long b[10];
    long long mb=0;
    long long ma=0;
    for(long long i=1;i<10;i++){
    cin>>b[i];}
    if(((b[1]+b[5]+b[9])==(b[2]+b[6]+b[7])&&(b[2]+b[6]+b[7])==(b[3]+b[4]+b[8]))&&((b[1]+b[6]+b[8])==(b[3]+b[5]+b[7])&&(b[3]+b[5]+b[7])==(b[2]+b[4]+b[9]))){
    cout<<"Yes"<<endl;}
    else
    cout<<"No"<<endl;}