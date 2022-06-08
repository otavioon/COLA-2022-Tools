#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
char s[110];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    ll k;
    cin >> k;
    ll n=strlen(s);
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
    	ll p=1;
    	while(s[i]==s[i+1])
    		{
    			p++;
    			i++;
    		}
    	ans+=p/2;
    }
    //cout << ans << "\n";
    if(s[n-1]==s[0])
    {
         ll i=0,p=0;
         while(s[i]==s[0] && i<n)
         	{
         		p++;
         		i++;
         	}
         ans-=p/2;
         //i=n-1;
         ll q=0;
         ll f=0;
         if(i==n)
         	f=1;
         if(i!=n)
         {
	         i=n-1;
	         while(s[i]==s[n-1] && i>=0)
	         {
	         	i--;
	         	q++;
	         }
	     }
	     if(f==1)
	     {
	     	cout <<  (k*p)/2 << "\n";
	     	return 0;
	     }
         ans-=q/2;
         ans = ans*k;
         ans+=(k-1)*(p+q)/2;
         ans+=p/2;
         ans+=q/2;
         cout << ans << "\n";
    }
    else
    {
    	cout << ans*k << "\n";
    }


	return 0;
}