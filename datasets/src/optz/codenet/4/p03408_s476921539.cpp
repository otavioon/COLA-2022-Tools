#include<bits/stdc++.h>
using namespace std;
/*bool is(long long a){
    if(a==2) return true;
    if(a<=1||a%2==0) return false;
    for(int i=3;i*i<=a;i+=2){
        if(a%i==0) return false;
    }
    return true;
}*/
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //cout.setf(ios_base::fixed,ios_base::floatfield);
    int n,m,z=0;
    set<string> s;
    cin>>n;
    string q[n];
    
    for(int i=0;i<n;i++){
        cin>>q[i];
        
    }
    cin>>m;
    pair<string,int> a[n+m];
    for(int i=0;i<n;i++){
        a[i].first=q[i];
        a[i].second=1;
        s.insert(a[i].first);
    }
    for(int i=n;i<m+n;i++){
        cin>>a[i].first;
        a[i].second=-1;
        s.insert(a[i].first);
        
    }
    sort(a,a+n+m);
    for(int i=0;i<n+m;i++){
        if(a[i-1].first==a[i].first){
            a[i].second+=a[i-1].second;
            a[i-1].second=0;
        }
        z=max(z,a[i].second);
    }
    cout<<z<<'\n';
    return 0;
}