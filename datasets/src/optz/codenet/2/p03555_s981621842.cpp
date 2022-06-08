#include<bits/stdc++.h>
//#include <boost/lexical_cast.hpp>
using namespace std;

#define pb push_back
#define mp make_pair  //access values using v[i].first,v[i].second
#define mt make_tuple //access values using get<1>(v[i]),get<0>(v[i]) etc

#define inf 1000000000
#define mod 1000000007

#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w",stdout)

#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sc(n) scanf("%c",&n)
#define sd(n) scanf("%lf",&n)

#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pdn(n) printf("%lf\n",n)

#define pis(n) printf("%d ",n)
#define pls(n) printf("%lld ",n)

#define pn printf("\n")
#define ps(n) printf("%s",n)
#define psn(n) printf("%s\n",n)

vector<int> primes;  //primes.size() = 78498 //last prime number = 999983
void sieve()
{
    vector<bool> a(1000000,false);
    for(int u=2;u<=1000000;u++)
    {
        if(a[u])continue;
        for(int i=2*u;i<=1000000;i+=u)a[i]=true;
    }
    for(int i=2;i<=1000000;i++)
    {
        if(!a[i])primes.pb(i);
    }
}

int gcd(int a, int b)
{
    while(1)
    {
        if(a==0)return b;
        b%=a;
        if(b==0) return a;
        a%=b;
    }
}
int lcm(int a, int b)
{
    int g=gcd(a,b);
    return ((a*b)/g);
}

int digitCount(int n)
{
    int c=0;
    while(n!=0)
    {
        c+=n%10;
        n/=10;
    }
    return c;
}

int totalDigit(int n)
{
    int d;
    for(d=1,n/=10;n!=0;n/=10)d++;
    return d;
}


int parseInt(string str)
{
    int a=0;
    int l=str.length();
    for(int i=0;i<l;i++)
    {
        a*=10;
        a+=str[i]-48;
    }
    return a;
}

long long parseLong(string str)
{
    long long a=0;
    int l=str.length();
    for(int i=0;i<l;i++)
    {
        a*=10;
        a+=str[i]-48;
    }
    return a;
}

int main()
{
    //FIN;
    string st1,st2;
    cin>>st1;
    cin>>st2;
    reverse(st1.begin(),st1.end());
    if(st1==st2)psn("YES");
    else psn("NO");
}
