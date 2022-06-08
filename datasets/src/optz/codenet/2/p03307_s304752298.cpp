#include<iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define vi vector<int>
#define lvi vector<long long>
#define pi pair<int,int>
#define lpi pair<long long ,long long>
#define mp make_pair
#define pb push_back
#define ll long long 
#define faltu ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 1000000000000000007
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>multiordered_set;
ll int pw(ll int a, ll int b,ll md) {
    if (b == 0) return 1;
    ll int t = pw(a, b / 2,md);
    if (b % 2 == 0) return (t * t)%mod;
    else return ((t * t)%mod * a)%mod;
}
vector<int> pm;
void prm(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
              prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p]) pm.push_back(p);
}
bool cmp(const pair<ll int,ll int> &a,const pair<ll int,ll int> &b)
{
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}
ll int gcd(ll int a,ll int b)
{
    if(!a)return b;
    return gcd(b%a,a);
}
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 
map<int,int>pa;
int find(int i){
    if(pa[i]==i)return i;
    return pa[i]=find(pa[i]);
}     
void join(int i,int j){
    int a=find(i);
    int b=find(j);
    if(b>=a)pa[b]=a;
    else pa[a]=b;
}               
int ddx[]={-1,-1,-1,0,1,1,1,0};
int ddy[]={-1,0,1,1,1,0,-1,-1};
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int main()
{
    faltu;
    int t=1;
   // cin>>t;
    while(t--)
    {
       ll x;
       cin>>x;
       if(x%2)x*=2;
       cout<<x<<endl;
    }
}