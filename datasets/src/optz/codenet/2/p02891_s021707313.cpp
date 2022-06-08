#include<bits/stdc++.h>

using namespace std;

#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define Eunique(v) v.erace(unique(all(v)),v.end())
#define pvec(v)　rep(i,v.size()){cout << v[i] << " ";}
#define INF 0x3f3f3f3f
#define mset(m,v) memset(m,v,sezeof(m))
#define mod (ll)(1e9 +7);

const double pi = acos(-1.0);

typedef vector<int> vi;
typedef string ss;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef deque<ll> dll;
typedef pair<ll, ll> P;
ll dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

ll gcd(ll x,ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}

ll digsum(ll n){
    ll sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

string to_binString(int val)
{
    if( !val )
        return std::string("0");
    string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}

map<ll,int> prime_factor(ll n){
    map<ll, int> ret;
    REP(i,2,sqrt(n) + 1){
        while(n%i == 0){
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)ret[n] = 1;  
    return(ret);
}
int main()
{
    string s;
    ll n,cnt = 0,tmp = 0;
    bool plus = true,pass;
    cin >> s >> n;
    REP(i,1,SIZE(s)){
        pass = false;
        if(s[i] == s[i-1]){
            cnt++;
            pass = true;
        }
        if(i == SIZE(s)-1 && s[i] == s[i-1])plus = false;
        if(pass)i++;
    }
    
    if(s[0] == s[SIZE(s)-1])tmp++;
    ll ans = cnt * n;
    if(plus)ans += tmp * (n-1);
    cout << ans << endl;
    //cout << "cnt = " << cnt << " tmp = " << tmp << endl;
    //cout << plus << endl;
    return 0;
}