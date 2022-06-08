//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define MOD 1000000007

int main()

{

    ll  s=0,s1=0;
    for(ll i=  0; i < 3; i++)
    {

        for(ll j = 0; j < 3; j++)
        {

            ll x;
            cin >> x;
            s+=x;
            if(i==j)
                s1+=x;
        }
    }
    if(s%3==0)
    {

        if(s1==(s/3))
            cout << "Yes";
        else
            cout << "No";
    }
    else
        cout << "No";
}
