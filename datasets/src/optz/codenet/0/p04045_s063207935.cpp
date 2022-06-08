#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (long long i = (s); i < (long long)(n); i++)

int main() {
    int n,k;
    cin>>n>>k;

    vector<int>dl(10);
    rep(i,0,k){
        int d;
        cin>>d;
        dl[d]++;
    }

    for (int i=n;i<100000;i++) {
        int x=i;
        bool jdg=true;
        while(x>0){
            if(dl[x%10]==1){
                jdg=false;
            }
            if(jdg==false){
                break;
            }
            x/=10;
        }
        if(jdg){
            cout<<i<<endl;
            break;
        }
    }
}