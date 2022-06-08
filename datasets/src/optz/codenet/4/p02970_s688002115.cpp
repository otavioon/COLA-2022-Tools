#include<bits/stdc++.h>
#define ll long long 
#define hell 1000000007 
#define F first
#define re 15000000
#define S second
#define pb push_back
#define all(a)  (a).begin(),(a).end()
#define rep(i,a,b) for(ll int i = a;i<b;i++)
#define pi 3.1415926536
#define Mod 998244353
//char a[2000][2000];
using namespace std;
int sum (ll a)
{
    int sum =0;
    while(a>0)
    {
        sum = sum + (a%10);
        a=a/10;
    }
    return sum;
}
int count_digit(ll n)
{
   int  count =0;
    while(n>0)
    {
        n = n/10;
        count++;
        //count++;
    }
    return count;
}
int binarySearch(int x,int y ,ll z ,ll v[])
{
    int low = x;
    int high = y;
    int mid = x+(y-x)/2;
    while(low<=high)
    {
        if(v[mid]==z)
            return mid;
        if(v[mid]<z)
            return binarySearch(mid+1,high,z,v);
        if(v[mid]>z)
            return binarySearch(low,mid-1,z,v);
    }
    return -1;
}
ll modularExponentiation(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

} 
ll binaryExponentiation(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}




set<ll> s;
//vector<ll> v;
void genrate(ll n,int len,int max)
{
    if(len>max)
        return ;
    s.insert(n);
    genrate(n*10+1,len+1,max);
    genrate(n*10+0,len+1,max);
}
/*bool visited[100005];
vector<ll> v[100005];
bool recur[100005];
bool dfs(int x)
{
    if(recur[x])
        return true;
    if(visited[x])
        return false;
    recur[x] = true;
    visited[x]= true;
    for(int i =0;i<v[x].size();i++)
    {
        if(visited[v[x][i]]!=1 ,dfs(v[x][i]))
            return true;
            
        else if (recur[v[x][i]])
            return true;
    }
    recur[x] = false;
    return false;

}*/
//memset(level,0,sizeof(level));    
/*void topological_sort(int x)
{
    visited[x] = 1;
  //  sort(all(v[x]));
    for(int i =0;i<v[x].size();i++)
    {
        if(visited[v[x][i]]!=1){
            //level[v[x][i]] = level[x]+1;
            topological_sort(v[x][i]);
        }
    }
    ans.pb(x);
}*/
//char a2001][2001];
///**************** Cycle using DSU *********************///

int findPivot(ll a[],int low,int high)
{
    int mid = (low+high)/2;
    if(high < low)
      return -1;
     if(low == high)
      return low;
    if(a[mid] >= a[mid+1] && mid < high)
      return mid;
     if(a[mid-1] >=a[mid] && mid > low)
      return mid-1;
     if(a[mid] >= a[low])
         return findPivot(a,mid+1,high);
     if(a[mid] <= a[low])
      return findPivot(a,low,mid-1);
}
bool isSubSequence(string str1, string str2, int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
  
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    // If last characters are not matching 
    return isSubSequence(str1, str2, m, n-1); 
}
ll  recur(vector<pair<ll,ll> >&dp,ll a[],ll b[],int flag,int n){
  if(n < 0)
     return 0;
  

  if(flag == -1){
       ll res1 = a[n] + recur(dp,a,b,1,n-1);
       ll res2 = b[n]+recur(dp,a,b,0,n-1);
       ll res3 = recur(dp,a,b,-1,n-1);
       ll maxi = max(res1,max(res2,res3));
    //   cout<<maxi<<" ";
       if(maxi == res1){
        //dp[n] = {maxi,1};
        dp[n].F = maxi;
        dp[n].S = 1;
       }
       if(maxi == res2){
        dp[n].F = maxi;
        dp[n].S = 0;
        //dp[n] = {maxi,0};
       }
       if(maxi == res3){
         dp[n].F= maxi;
         dp[n].S = -1;
        //dp[n] = {maxi,-1};
       }
       //dp[n].F = max(a[n] + recur(dp,a,b,1,n-1) ,max(b[n]+recur(dp,a,b,0,n-1) , recur(dp,a,b,-1,n-1)));
      // cout<<a[n] + recur(dp,a,b,1,n-1)<<" "<<b[n]+recur(dp,a,b,0,n-1)<<" "<<recur(dp,a,b,-1,n-1)<<endl;
     //  cout<<dp[n]<<" ";
       return dp[n].F;
   } 
  else if(flag == 1){
    ll res1 = b[n] + recur(dp,a,b,0,n-1);
    ll res2 = recur(dp,a,b,1,n-1);
      //dp[n].F = max(b[n] + recur(dp,a,b,0,n-1) ,recur(dp,a,b,1,n-1));
      //cout<<dp[n]<<" ";
      ll maxi = max(res1,res2);
      if(maxi == res1){
        dp[n].F = maxi;
        dp[n].S = 0;
      }
      if(maxi == res2){
        //dp[n] = {maxi,1};
        dp[n].F = maxi;
        dp[n].S = 1;
      }
      return dp[n].F;
   }
   else if(flag == 0){
    ll res1 = a[n] + recur(dp,a,b,1,n-1);
    ll res2 = recur(dp,a,b,0,n-1);
      //dp[n].F = max(b[n] + recur(dp,a,b,0,n-1) ,recur(dp,a,b,1,n-1));
      //cout<<dp[n]<<" ";
      ll maxi = max(res1,res2);
      if(maxi == res1){
         //dp[n] = {maxi,1};
        dp[n].F = maxi;
        dp[n].S = 1;
      }
      if(maxi == res2){
       dp[n].F = maxi;
        dp[n].S = 0;
      }
      return dp[n].F;
   }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);            
    //std::setprecision(20);    
    int tests=1;
      //freopen("input.txt", "r", stdin);
     //cin>>tests;
   while(tests--)
    { 
      int n,d;
     cin>>n>>d;
      cout<<ceil(1.0*n/(2*d+1));
    }

}