#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define mod 1000000007;
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n-1];
    for(int i=0;i<n-1;i++)
    cin>>arr[i];
    ll temp=-1,ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
        {
        ans+=2*arr[i];
        temp=arr[i];
        continue;
        }
        else if(temp>arr[i])
        {
            ans-=temp;
            ans+=2*arr[i];
            temp=arr[i];
        }
        else if(temp<=arr[i])
        {
            ans+=arr[i];
            temp=arr[i];
        }

    }
    cout<<ans;

    

    return 0;
}