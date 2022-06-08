#include <bits/stdc++.h>
using namespace std;

#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ones __builtin_popcount
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define sd(x) scanf("%lf",&x)
#define ss(x) scanf("%s",x)
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define debug(x) cerr << "debug = " << x << "\n";
#define debugs(s,x) cerr << "debug : " << s << " = " << x << "\n";
#define cnd tree[idx]
#define lnd tree[idx*2]
#define rnd tree[(idx*2)+1]
#define lndp (idx*2),(b),((b+e)/2)
#define rndp (idx*2+1),((b+e)/2+1),(e)
#define X real()
#define Y imag()
#define Point complex<long double>
#define pi 2.0*acos(0.0)
#define EPS 1e-9
#define INF INT_MAX
#define MOD 1000000007
#define MAX 100005

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

LL f(string s, LL k)
{
    int n = s.size();

    if(n == 1) return (k/2);

    LL cnt = 0, mx = 0;
    bool flag = false;

    FOR(i,1,n)
    {
        if(i == n)
        {
            if(k > 1 && s[0] == s[n-1])
            {
                cnt += (k-1);
                flag = true;
            }
            break;
        }
        if(s[i] == s[i-1])
        {
            cnt += k;
            i++;
        }
    }

    mx = cnt;
    cnt = 0;

    if(flag)
    {
        cnt = k-1;
        FOR(i,2,n-1)
        {
            if(s[i] == s[i-1])
            {
                cnt += k;
                i++;
            }
        }
        mx = min(mx, cnt);
    }

    cnt = 0;

    FOR(i,0,n-1)
    {
        if(i == n-1)
        {
            if(k > 1 && s[i] == s[0])
                cnt += (k-1);
        }
        else
        {
            if(s[i] == s[i+1])
            {
                s[i] = '0';
                cnt += k;
                i++;
            }
        }
    }

    mx = min(mx, cnt);

    return mx;
}

int main()
{
    //READ("input.txt");
    //WRITE("out.txt");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //uniform_int_distribution<int>(0, 10000)(rng)
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, sum;
    string s;

    cin >> s >> k;

    cout << f(s,k);

    return 0;
}



