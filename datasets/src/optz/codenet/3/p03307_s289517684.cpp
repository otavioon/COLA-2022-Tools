#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long M = 1e9+7;
long long power(long long a, long long p)
    {
        if(p==0) return 1;
        long long ans= power(a,p/2);
        ans =(ans * ans) % M;
        if(p%2) ans = (ans*a) % M;
        return ans;
    }

    bool isPrime(long long n)
    {
        if (n <= 1)
            return false;
        for (long long i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    long long SieveOfEratosthenes(long long n, long long a)
    {
        bool prime[n+1];
        memset(prime, true, sizeof(prime));
        for (long long p=2; p*p<=n; p++)
        {
            if (prime[p] == true)
            {
                for (long long i=p*p; i<=n; i += p)
                    prime[i] = false;
            }
        }
        for (long long p=2; p<=n; p++)
           if (prime[p])
           {
               if(a%p==0)
               {
                   return (a-p);
               }
           }
    }
    long long nCr(int n, int r)
    {
        if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
        long long ans = 1;
        int i;
        for(i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
        return ans;
    }
int main()
{
    IOS;
    long long a,b,c,d,e,h,n,t,f,m,f1=0,flag=0,flag1=0,co=0,co1=0,co2=0,arr1[100001]={0},sum=0,sum1=0,ma=0,ma1=0,mi=1000000000000000001;
    long long g,co3=0,co4=0,co5=0,co6=0,co7=0,co8=0,mul=1,sum2=0,sum3=0,mu=1,mu1=1;
    long long a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,b6;
    double pi=2 * acos (0.0);
    string str,str1,str2,str3,str4,str5,str6;
    char ch,ch1;
    //vector<long long>v; //vector<long long> v(n+1);
    //vector<long long>v1;
    // vector<string>vs;
    // vector<string>vs1;
    vector<char>vc;
    //map<long long,long long>mp;
    map<char,int>mp1;
    //set<long long>s;
    set<long long>s1;
    queue<long long> q;
    //stack<long long> stk;
    //vector< pair<long long,long long> >v3;
    //map<long long,long long>::iterator it;
    //map<string,string>::iterator it;
    // vector<pair<char, pair<int,int> > > v3;
    //vector< pair<char,int > > v1;
    int x[]={1,1,1,0,0,-1,-1,-1};
    int y[]={0,1,-1,1,-1,1,-1,0};
    cin>>n;
    if(n%2==0) cout<<n<<endl;
    else cout<<n*2<<endl;
    return 0;
}
