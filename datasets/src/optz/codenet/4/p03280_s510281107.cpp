#include<bits/stdc++.h>
using namespace std;
int ans;

int main(){
    int n; cin >> n;
    if(n >= 105)ans++;
    if(n >= 165)ans++;
    if(n >= 195)ans++;
    if(n >= 135)ans++;
    if(n >= 189)ans++;
    cout<<ans;
    return 0;
}
