#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    
    int ans = 0, prev;

    int b[n-1];

    for(int i=0;i<n-1;i++){
        cin>>b[i];
        if(i == 0){
            ans += b[i] + b[i];
            prev = b[i];
            continue;
        }
        if(b[i] < prev){
            ans -= prev;
            ans += b[i] + b[i];
            prev = b[i];
        }
        else{
            ans += b[i];
            prev = b[i];
        }   
    }
    cout<<ans<<endl;
}