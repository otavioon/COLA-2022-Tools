#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
multiset<ll> s;
int main(){
    cin>>n;
    while(n--)cin>>a,s.insert(a);
    while(s.size()){
        a=*s.rbegin();
        s.erase(s.find(a));
        ll p=1;
        while(p<=a)p*=2;
        if(s.find(p-a)!=s.end())s.erase(s.find(p-a)),b++;
    }
    cout<<b<<'\n';
}