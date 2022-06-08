#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int inf=1000000007;

double a[200005];
int n, k;

string s;

bool fun(double d)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans+ceil(a[i]/d);
        ans--;
        if(ans>k)
        {
            return 0;
        }
    }
    if(ans<=k)
    {
        return 1;
    }
    return 0;
}

double erfen(double l,double r)
{
    while(r-l>=0.0001)
    {
        double z=(l+r)/2;
        if(fun(z))
        {
            r=z;
        }
        else
        {
            l=z;
        }
    }
    return r;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double z=erfen(0.0,1000000007.0);
    printf("%d",ceil(z));
    return 0;
}
