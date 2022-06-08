#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int n=(int)s.size();
    int k;cin>>k;
    if (s[0]!=s.back()){
        int cnt=1;
        int res=0;
        for (int i=1;i<n;i++){
            if (s[i]==s[i-1]) cnt++;
            else res+=cnt/2,cnt=1;
        }
        res+=cnt/2;
        cout<<res*k;
    } else {
        string t=s;
        sort(t.begin(),t.end());
        if (t==s) cout<<(n*k)/2;
        else {
            int l=0;
            while (s[0]==s[l]) l++;
            int cnt=1;
            int res=0;
            for (int i=l+1;i<n;i++){
                if (s[i]==s[i-1]) cnt++;
                else res+=cnt/2,cnt=1;
            }
            res*=k;
            res+=l/2;
            res+=cnt/2;
            res+=((l+cnt)/2)*(k-1);
            cout<<res;

        }
    }
    return 0;
}
