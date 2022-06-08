#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define me BOSS
#define bug() cout<<"AIkahne aise"<<endl
ll A[5000001],bin[5000001];
vector<ll>v;
map<int,int>myMap;
set<int>mySet;
vector<pair<ll,ll> >vp;
/* Precode Start Here *\


    Integer  to Binary

void bti(ll n)
{
ll k=1;
  while(n!=0)
    {
    bin[k++]=n%2;
    n/=2;
    }
}

     Sieve
void sieve()
{
    for(ll i=3; i<=2000; i+=2)
    {
        for(ll j=i*i; j<=4000000; j+=i)
            A[j]=1;
    }
    v.push_back(2);
    for(ll i=3; i<=4000000; i+=2)
        if(A[i]==0)
            v.push_back(i);
}

     Power Function Modulo P

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}


   factorial

ll fact(ll n)
{
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        ans=(ans*i)%mod;
    }
    return ans;
}
     Calculating nCr using Fermats law Theorem

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}


ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (ll i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ll denominator = 1; // k!
    for (ll i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}


/* Precode Ends */
int main()
{
    ll k,cnt=0,inside=0;
    string s;
    cin>>s;
    cin>>k;
    string t=s;
    ll start=0,finish=s.size()-1;

    while(s[start]==t[finish])
    {
        cnt++;
        start++;
        finish--;
        if(start>=s.size())
            break;
    }
    start=0,finish=s.size()-1;
    ll i=0;
    while(s[i]==s[finish])
    {
        i++;
    }
    //cout<<i<<"dui"<<endl;
    for(ll j=i; j<s.size()-1; j++)
    {
        if(s[j]==s[finish]&&s[start]==s[finish])
            goto x;
        if(s[j]==s[j+1])
        {
            //cout<<s[j]<<" dd "<<s[j+1]<<endl;
            while(s[j]==s[j+1])
            {
                inside++;
                j+=2;
                if(j>=s.size())
                    break;
                if(s[j]==s[finish]&&s[start]==s[finish])
                        goto x;
            }
        }
    }
    x:
        ll first=0,last=0;
        i=0,finish=s.size()-1;
    //cout<<cnt<<" "<<inside<<endl;
    while(s[i]==s[start])
        i++,first++;
    while(s[finish]==s[s.size()-1])
    {
        finish--,last++;
    }
    ll q=k-1,ase=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
            ase++;
    }
    if(ase==s.size()-1)
    {
        first=0;
        if(k%2==0)
            last=0;
        q=k/2;
    }
    cout<<cnt*q+inside*k+first/2+last/2<<endl;
    //for(int i=0,j;i<s.size();i++)
    return 0;
}

