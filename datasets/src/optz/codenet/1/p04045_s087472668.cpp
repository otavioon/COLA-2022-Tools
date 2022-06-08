#include<bits/stdc++.h>
using namespace std;

vector<bool> vec(10,true);

int solve(int val,int N,bool flag){
    if(val>=N) return val;
    int ans = INT_MAX;
    if(flag){
        for(int i=1;i<10;++i){
            if(vec[i]==true) ans = min(ans,solve(val*10 +i,N,false));
        }
    }
    else{
        for(int i=0;i<10;++i){
            if(vec[i]==true) ans = min(ans,solve(val*10 +i,N,false));
        }
    }
    return ans;
}

int main(){
    int N,k,t;
    cin>>N>>k;
    for(int i=0;i<k;++i){
        cin>>t;
        vec[t]=false;
    }
    cout<<solve(0,N,true);
    return 0;
}
