#include <bits/stdc++.h>
#define db double
using namespace std;
int n,m;
set <db> s;
db p,a,i;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a;
        s.insert(a);
    }
    for (int i=1; i<=m; i++)
    {
        set <db> :: iterator it = s.end(); it--;
        p=*it; s.erase(p);
        s.insert(p/2);
        s.insert(p/2);
    }
   set <db> :: iterator it = s.end(); it--; p=*it;
   cout<<fixed<<setprecision(0)<<p;
}
