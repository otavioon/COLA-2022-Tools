#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;cin>>n;
    int a[n],b[n],c[n];
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++)cin>>b[i];
    for (int i=0;i<n;i++)cin>>c[i];
    sort(a,a+n);sort(b,b+n);sort(c,c+n);
    int p,q;
    int ans=0;
    for (int i=n-1;i>=0;i--){
        for (int q=n-1;q>=0;q--){
            if (b[q]<c[i]){
                for (int p=n-1;p>=0;p--){
                    if (a[p]<b[q]){
                        ans+=p+1;
                        break;
                    }
                }
            }
        }
    }cout<<ans;
    return 0;
}
