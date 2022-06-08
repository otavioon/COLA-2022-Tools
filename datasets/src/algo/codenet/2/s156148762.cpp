#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cstdio>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007

#define ARRAY_MAX 10005


int main(){

    int n,a;
    cin >> n;
    multiset<int> st;
    REP(i,n){
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    while(!st.empty()){
        auto itr = st.end();
        itr--;
        int x = *itr;
        st.erase(itr);
        int num = 1;
        for(num = 1;num <= x;num *= 2);
        if(st.find(num-x) != st.end()){
            st.erase(st.find(num-x));
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}