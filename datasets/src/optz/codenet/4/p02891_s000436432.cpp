#include<bits/stdc++.h>
using namespace std;

#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))

int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };



template <class T> inline T biton(T n, T pos)
{
    return n | ((T)1 << pos);
}
template <class T> inline T bitoff(T n, T pos)
{
    return n & ~((T)1 << pos);
}
template <class T> inline T ison(T n, T pos)
{
    return (bool)(n & ((T)1 << pos));
}
template <class T> inline T gcd(T a, T b)
{
    while (b)
    {
        a = a%b;
        swap(a, b);
    }
    return a;
}
template <class T> inline T bigmod(T p, T e, T m)
{
    T ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
};

#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " is " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif

int dp[500][500];

string t;
int recur(int pos,int last)
{

    if(pos==(int)t.size())
    {

        return 0;
    }

    if(dp[pos][last]!=-1){
        return dp[pos][last];
    }

    int mn=1e17;

    for(int i='a'; i<='z'; i++)
    {
        if(i!=last)
        {
            mn=min(mn,(t[pos]!=i)+recur(pos+1,i));
        }
    }

    return dp[pos][last]=mn;

}

void solve()
{

    long long k;
    cin>>t>>k;

    set<char> items;

    for(auto z:t){
        items.insert(z);
    }

    if(t.size()==1){

        cout<<k/2<<endl;
        return;
    }

    if(items.size()==1){
        cout<<((long long)t.size()*k)/2ll<<endl;
        return;
    }



    SET(dp);

    long long ans=recur(1,t.front());
    t+=t;
    SET(dp);
    long long dblans=recur(1,t.front());
    long long res=ans*k;

    debug(ans,dblans);

    if(ans*2ll!=dblans){
        res+=k-1ll;
    }


    cout<<res<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
