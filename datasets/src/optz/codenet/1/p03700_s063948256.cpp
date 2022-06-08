#include <bits/stdc++.h>
using namespace std;

int64_t n,A,B,a[100005];

bool Check(int64_t x)
{
    for(int i=1;i<=n;i++)
        a[i]-=x*B;
    int64_t Count=0;
    for(int i=1;i<=n;i++)
        if(a[i]>0)
            Count+=a[i]/A+(a[i]%A>0);
    for(int i=1;i<=n;i++)
        a[i]+=x*B;
    return Count<=x;
}

void Binary()
{
    int64_t res,l=1,r=1e9;
    while(l<=r)
    {
        int64_t mid=(l+r)/2;
        if(Check(mid)==true)
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<res;
}

int main()
{
    cin>>n>>A>>B;
    A-=B;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    Binary();
}
