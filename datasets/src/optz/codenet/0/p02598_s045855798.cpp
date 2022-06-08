using namespace std;
#include <bits/stdc++.h>
#define frr(i, r, l) for(int i = r; i >= l; --i)
#define fr(i, l, r) for(int i = l; i < r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define MEMS(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define ll long long
#define ld long double
typedef pair<ll, ll> iPair; 
priority_queue< ll, vector <ll> , greater<ll>>pq1,pq2;
#define maxN 1000000000000000000
ll power(ll a,ll b){ll res=1;while(b>0){res*=a;b--;}return res;}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,m,l,h,ar[200005],ans;
    cin>>n>>k;

    fr(i,0,n)
    {
        cin>>ar[i];
    }

    l=0;
    h=1000000000;
    while(l<=h)
    {
        m=(l+h)/2;
        
        ll tot=0,lng,cnt,j;
        fr(i,0,n)
        {
            if(ar[i]>m && m!=0)
            {
                cnt=ar[i]/m;
                cnt-=1;
                if(cnt*m!=ar[i])
                cnt+=1;
                
    
                tot+=cnt;
            }
        }
        if(m==0)
        tot=maxN;
    
        if(tot>k)
        {
            l=m+1;
        }
        else
        {
            ans=m;
            h=m-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}