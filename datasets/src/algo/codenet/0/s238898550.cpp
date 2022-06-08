#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 1001
using namespace std;
int n,m;
char s[MAXN];
int main()
{
    scanf("%s",s);
    scanf("%d",&n);
    m=strlen(s);
    
    if(s[0]!=s[m-1])
    {
        LL ans=0;
        for(int i=1,j=1;i<m;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans+=j/2;
                j=0;
            }
            j++;
        }
        cout<<ans*n<<endl;
    }
    else
    {
        LL ans=0;
        int L=0,R=m-1;
        while(s[L]==s[0]&&L<m)L++;
        while(s[R]==s[m-1]&&R)R--;
        if(L==m)
        {
            cout<<n*(LL)m/2<<endl;
            return 0;
        }
        ans+=(L+m-1-R)/2;
        for(int i=L,j=0;i<=R+1;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans+=j/2;
                j=0;
            }
            j++;
        }
        //cout<<L<<" "<<R<<" "<<ans<<endl;
        ans=ans*n;
        ans-=(L+m-1-R)/2;
        ans+=L/2+(m-1-R)/2;
        cout<<ans<<endl;
    }
    
    return 0;
}
