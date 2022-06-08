#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll K;
    cin >> K;

    ll cnt_in = 0;
    char prec = 'A';
    for(auto c : s)
    {
        if(prec == c)
        {
            cnt_in++;
            prec = 'A';
        }
        else prec = c;
    }

    ll cnt_soto_begin = 0;
    prec = s[0];
    for(auto c : s)
    {
        if(prec == c) cnt_soto_begin++;
        else break;
    }
    ll cnt_soto_end = 0;
    for(int i=s.size()-1; i>=0; i--)
    {
        if(prec == s[i]) cnt_soto_end++;
        else break;
    }
    if(cnt_soto_begin == s.size())
    {
        cout << K * s.size() / 2 << endl;
        return 0;
    }

    cout << K * cnt_in + (K-1) * ((cnt_soto_begin%2==1 && cnt_soto_end%2==1) ? 1 : 0) << endl;




    return 0;
}
