#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long k;
    cin>>k;
    int n=s.size();
    if(n==1){
        cout<<k/2<<endl;
        return 0;
    }
    long long uni=0;
    bool fc=false;
    bool c=false;
    if(s[0]==s[1]){
        fc=true;
        c=true;
        ++uni;
    }
    for (int i = 1; i < n-1; ++i) {
        if(s[i]==s[i+1]){
            if(!c){
                ++uni;
                c=true;
            }
            else c=false;
        }
        else c=false;
    }
    long long ans=0;
    if(s.back()==s.front()){
        if(!fc){
            if(!c)ans+=k-1;
        }
    }
    ans+=uni*k;


    cout<<ans<<endl;
    return 0;
}