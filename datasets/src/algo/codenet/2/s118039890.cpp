#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<ll>st;
    f (n) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while (st.size()) {
        int x = *(--st.end());
        st.erase(st.lower_bound(x));
        for (int i = (1<<30) ; i ; i>>=1){
            if (i <= x) {
                break;
            }
            if (st.find(i-x) != st.end()) {
                ans++;
                st.erase(st.lower_bound(i-x));
                break;
            }
        }
    }
    cout << ans << '\n';
}
    

