#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int sum = 0, c;
    rep(i,9) cin>>c, sum+=c;
    cout<<(sum%3==0 ? "Yes" : "No")<<endl;
    return 0;
}
