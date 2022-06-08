#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a.at(i);
    }
    vector<bool> b(n+1,false);
    int ans=0;
    int i=1;
    while(1){
        ans++;
        b.at(i)=true;
        i = a.at(i);
        if(i==2){
            cout << ans << endl;
            return 0;
        }
        if(b.at(i)) break;
    }
    cout << -1 << endl;
}
