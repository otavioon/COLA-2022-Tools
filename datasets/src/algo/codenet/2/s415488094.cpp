#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define go(i,a,b) for(int i=a;i<=b;i++)
#define og(i,a,b) for(int i=a;i>=b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define Pi acos(-1)
#define eps 1e-8
using namespace std;
typedef long long int ll;
const int maxn=2*1e5+5;
const ll inf=0x3f3f3f3f;
const int mod=1e9+7;
multiset <int> s;
int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x; scanf("%d",&x);
        s.insert(x);
    }
    int ans=0;
    while(!s.empty())
    {
        multiset <int> ::iterator it=s.end();
        it--;
        int x=*it;
        s.erase(it);
        for(n=1;n<=x;n*=2);
        if(s.find(n-x)!=s.end())
            ans++,s.erase( s.find(n-x) );
    }
    printf("%d\n",ans);
    return 0;
}
