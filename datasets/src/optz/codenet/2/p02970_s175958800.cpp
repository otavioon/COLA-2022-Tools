#include <bits/stdc++.h>
using namespace std;

#define int long
#define pb push_back
#define X first
#define Y second
#define rf(i,l,n) for(int i=n-1;i>=l;i--)
#define mod 1000000007
#define el endl
#define mux INT_MAX
#define mun -INT_MAX
#define f(i,l,n) for(int i=l;i<n;i++)
#define v vector
#define mp make_pair
#define pq priority_queue
#define graph vector<int> 
#define pin pair<int,int>
int gcd(int a,int b)
{
if(a>=b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
    else
    {
        if(a==0)
        return b;
        else
        return gcd(a,b%a);
    }
    
}

int min(int a,int b,int c)
{
    if(a<=b&&a<=c)
    return a;
    else if(b<=a&&b<=c)
    return b;
    else
    return c;
}
int max(int a,int b,int c)
{
    if(a>=b&&a>=c)
    return a;
    else if(b>=a&&b>=c)
    return b;
    else
    return c;
}
long long pw(long long a,long long b)
{
int d=1;
for(int i=0;i<b;i++)
d=d*a;


    return d;
    
}



//func for segment tree 
int ip[100000];
int sgt[100000];
int sgt2[100000];
int 
int calcnp(int n)
{
    int i=0;
    while(pow(2,i)<n)
        i++;
    return 2*pow(2,i)-1;



}
//creation of sgt 
void cst(int ip[],int sgt[],int low,int high,int pos)
{
    if(low==high){
        sgt[pos]=ip[low];
        return;
    }
    int mid=(low+high)/2;
    cst(ip,sgt,low,mid,2*pos+1);
    cst(ip,sgt,mid+1,high,2*pos+2);
    sgt[pos]=min(sgt[2*pos+1],sgt[2*pos+2]);
    return;

}

//creation of max segment
void cst2(int ip[],int sgt2[],int low,int high,int pos)
{
    if(low==high){
        sgt2[pos]=ip[low];
        return;
    }
    int mid=(low+high)/2;
    cst2(ip,sgt2,low,mid,2*pos+1);
    cst2(ip,sgt2,mid+1,high,2*pos+2);
    sgt2[pos]=max(sgt2[2*pos+1],sgt2[2*pos+2]);
    return;

}

//query for min of segment tree
int minq(int sgt[],int lq,int hq,int low,int high,int pos)
{

    if(lq>high||hq<low)
        return 10000;
    if((lq<=low)&&(hq>=high))
        return sgt[pos];
    int mid=(low+high)/2;
    return min(minq(sgt,lq,hq,low,mid,2*pos+1),minq(sgt,lq,hq,mid+1,high,2*pos+2));



}
//query for max seg tree
int minq2(int sgt2[],int lq,int hq,int low,int high,int pos)
{

    if(lq>high||hq<low)
        return -10000;
    if((lq<=low)&&(hq>=high))
        return sgt2[pos];
    int mid=(low+high)/2;
    return max(minq2(sgt2,lq,hq,low,mid,2*pos+1),minq2(sgt2,lq,hq,mid+1,high,2*pos+2));



}

//the segment tree function ends here
//hello this is aarsh

//the function for ncrmod p
int power(int x, int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
int nCrModPFermat(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 


//ncr mod p ends here



signed main() {
 std::ios::sync_with_stdio(false);
    
int n; cin>>n;
int d;
cin>>d;
if(2*d+1>n)
cout<<1;
else{
if(n%(2*d+1)==0)
cout<<n/(2*d+1);
else
cout<<n/(2*d+1)+1;
}
    return 0;
}