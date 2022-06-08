#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>
#include<functional>
#include<deque>

using namespace std;
typedef long long int ll;

#define C cout<<
#define E <<endl
#define CE cout<<endl
#define pb push_back

ll n,m,a,b,c,x,y,z,aa[200010],ab[200010],ac[1010];
bool r,ra,rb,rc[200010];
string s,sa,sb,sc;
char ca,cb,cc,cd[1010][1010];
vector<ll> va,vb,vc,vd,ve,vaa,vbb;
set<int> st;


int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>aa[i];
    }
    m=0;
    for(int i=0;i<n-2;i++){
        m+=min(aa[i],aa[i+1]);
    }
    C m+aa[0]+aa[n-2];

}