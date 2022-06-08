#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
# include <math.h>
#define lli long long int
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 57;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;

void solve()
{
    string s;
    cin>>s;
    lli n;
    cin>>n;
    lli cnt = 0;
    set<char> se;
    for(int i = 0; i < s.size(); i ++)
        se.insert(s[i]);
    bool ok = 0;
    if(s[0] == s[s.size() - 1])
        ok = 1;
    for(int i = 0; i < s.size() - 1; i ++)
    {
        if(ok && i == 0)
        {
            s[i] = '.';
            continue;
        }
        if(s[i] == s[i + 1])
            cnt ++, s[i + 1] = '.';
    }
//    cout<<cnt<<endl;
//    cout<<se.size()<<endl;
    if(s.size() == 1 || se.size() == 1)
    {
        lli ans = 0;
        ans = n * s.size();
        ans /= 2;
        cout<<ans;
        return ;
    }

    lli ans = cnt * n ;
  //  cout<<x<<endl;
    cout<<ans<<endl;
    return ;
}
/*
7
6 7 4 1 2 11 6
5
1 2 10 4 5
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli t;
    t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
