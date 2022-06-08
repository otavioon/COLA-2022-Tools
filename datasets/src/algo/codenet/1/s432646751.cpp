#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int sum=0;
    rep(i,9){
        int a;cin>>a;
        sum+=a;
    }
    if(sum%3==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}