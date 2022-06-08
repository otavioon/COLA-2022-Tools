#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.size();
    if(n==1){
        cout<<k/2<<endl;
        return 0;
    }
    long long uni=0;
    bool c=false;
    for (int i = 0; i < n-1; ++i) {
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
        if(!c)ans+=k-1;
    }
    ans+=uni*k;
    cout<<ans<<endl;
    return 0;
}