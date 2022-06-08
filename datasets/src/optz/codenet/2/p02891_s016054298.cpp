#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

int main()
{
    string s;

    ll k;

    cin >> s >> k;

    ll cnt = 0 ,cc;
    bool flag = 0;
    string t = s , s1 = s , t1 = s;

    for(int i=1;i<s.size();i++)
    {
        if(s[i] == s[i-1])
            cnt++ , s[i] = '.';
    }

    t = s[s.size()-1]+t;
    cc = cnt;
    ll ans = cnt;
    cnt = 0;
    for(int i=1;i<t.size();i++)
    {
        if(t[i] == t[i-1])
            cnt++ , t[i] = '.';
    }

    if(cc == cnt)
        ans += 1LL*cnt*(k-1);
    else
    {
        ans = (k-k/2)*cc + (k/2)*1LL*cnt;

        if(cc > cnt)
        {
            ans = (k-k/2)*cnt + (k/2)*cnt;

            ans--;
        }
    }


    cout << ans << endl;
}
