#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll

int t, n, m, k, a[300010], q, l, r;
multiset<int> s;

int32_t main(){
INIT
cin>>n>>k;
for(int i=1; i<=n; i++){cin>>a[i]; s.insert(a[i]);}
int l=0, r=((int)1000000000), m=(l+r)/2;


while(l<r){
      //  cout<<l<<" "<<r<<" ";
    m=(l+r)/2;
    int k0=k;
    int sz=(m);
    for(int i=1; i<=n; i++){
            if(sz==0){
                k0-=a[i]+a[i]-1; continue;
            }
        if( ((a[i])%sz)==0  ){
        k0-=max(( (int)( a[i]/sz) )-1, (int)0);}
        else{
            k0-=max(( (int)( a[i]/sz) ), (int)0);
        }
    }

    if(k0<0){
        l=m+1;
    }
    else{
        r=m;
    }
    m=(l+r)/2;
}
int k0=k;
int sz=m;

for(int i=1; i<=n; i++){
            if(sz==0){
               k0-=a[i]-1+a[i]; continue;
            }
    if( ((a[i])%sz)==0 ){
        k0-=max(( (int)( a[i]/sz) )-1, (int)0);}
        else{
            k0-=max(( (int)( a[i]/sz) ), (int)0);
        }
}
if(k0<0){m++;}
cout<<(m);


return 0;
}



