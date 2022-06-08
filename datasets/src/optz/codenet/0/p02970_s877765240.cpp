#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
// bitset<8>set1(p);
// __builtin_popcountll(x);
// bitset<100> b("1010");
long long power(long long a, long long b) {
    //a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
    }
  ll int binomial(ll int n, ll int k) 
{ 
    ll int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
  vector<int> pr;
  bool prime[10000000];
void Sieve(ll int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            pr.push_back(p);
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}
 


//It reurns Fn,Fn+1
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
void reverse(string& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
int fun(string s,char c)
{
    int n=s.length();
    if(n==1)
    {
        if(s[0]!=c)
        {
         return 1;
        }
        else {
        return 0;
        }
    }
    else {
    int l=0,k=0;
   int r=0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=c)
        {
           l++;
        }
    }
    for(int i=n/2;i<n;i++)
    {
        if(s[i]!=c)
        {
            k++;
        }
    }
   // cout<<l<<" "<<k<<endl;
   string p=s.substr(0,n/2);
        string o=s.substr(n/2,n/2);
        r+=min(k+fun(p,char(c+1)),l+fun(o,char(c+1)));
        return r;
    }
}



  
int main() {
       ll int n;
       cin>>n;
       ll int d;
       cin>>d;
       d*=2;
       d++;
       int l=n/d;
       if(n%d!=0)
       l++;
       cout<<l<<endl;
}
