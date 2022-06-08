#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define m 998244353
#define MAXN 50000 + 5
#define BLK_SIZE 225
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int ll 
#define all(arr) arr.begin() , arr.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i , a , n) for(int i = a ; i < n ; i++)
#define s(arr) sort(all(arr))
#define r(arr) reverse(all(arr))
#define rs(arr) s(arr) ; r(arr)
#define con continue
#define endl "\n"
 
//debug
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
int modexpo(int a , int b)
{
    int res = 1;
    while(b)
    {
        if (b & 1)
            res = (res * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return res;
}

signed main()
{
    int k , x;
    cin >> k >> x;
    if (k * 500 >= x)
    {
        cout <<"Yes";
    }
    else
        cout << "No";
    return 0;
}
