#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1145141919
typedef long long int ll;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

ll gcd(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    return m;
}

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

vector<ll> res; 

void decompositPrime(ll n)
{
    ll a = 2;
    while (n >= a * a)
    {
        if (n % a == 0)
        {
            res.push_back(a);
            n /= a;
        }
        else
        {
            a++;
        }
    }
    res.push_back(n);
}

int main(){
    ll N;
    cin >> N;

    decompositPrime(N);

    sort(res.begin(), res.end());
    ll ans = INF;

    if(res.size()==1){
        cout << to_string(N).size() <<endl;
        return 0;
    }else{
        ll hold=1, big=1;
        REP(i,res.size()){
            hold*=res[i];
            big = ll(N/hold);
            //cout << "hold = " << hold << " big = " << big << endl;
            if(ans>max(to_string(big).size(),to_string(hold).size())){
                //cout << "True hold = " << hold << " True big = " << big << endl;
                ans = max(to_string(big).size(), to_string(hold).size());
            }
        }
    }

    cout << ans << endl;

    return 0;
}