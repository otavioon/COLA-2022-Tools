#include <bits/stdc++.h>
using namespace std;
multiset <int> s;
int n,ans;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        s.insert(a);
    }
    while(!s.empty())
    {
        int t = *(--s.end()),k;
        for(k=1;k<=t;k*=2);
        s.erase(--s.end());
        if(s.find(k-t)!=s.end())
        {
            ans++;
            s.erase(s.find(k-t));
        }
    }
    printf("%d",ans);
}
