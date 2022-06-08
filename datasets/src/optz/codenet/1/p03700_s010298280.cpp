#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,b,a,minT,maxT,sumh=0,maxh=0;
    cin >> n >> a >> b;
    bool nenough = 1;
    vector<ll> h(n);
    for(int i = 0;i < n;i ++){
        cin >> h[i];
        sumh += h[i];
        maxh = max(maxh,h[i]);
    }
    minT = sumh/(n*b+a)+(sumh%(n*b+a)?1:0);
    maxT = maxh/b;
    ll mid = (minT+maxT)/2;
    while(nenough){
        ll cnt=0;
        for(int i = 0;i < n;i ++){
            cnt += (h[i]-mid*b)/(a-b)+((h[i]-mid*b)%(a-b)?1:0);
        }
        if(cnt==mid) nenough = 0;
        else if(mid>cnt) maxT=mid,mid=(minT+maxT)/2;
        else minT=mid,mid=(minT+maxT)/2;
    }
    cout << mid << endl;
    return 0;
}