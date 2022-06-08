#include <bits/stdc++.h>
using namespace std;
#define N 200010

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());

    int low=0;
    int high=a[n-1];
    int m=low+(high-low)/2;

    while(low!=m)
    {
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            int n=a[i]/m;
            if(n==0)break;
            cnt+=n;
        }

        if(cnt>k)low=m;
        else high=m;

        m=low+(high-low)/2;
    }

    cout<<high;

    return 0;
}

