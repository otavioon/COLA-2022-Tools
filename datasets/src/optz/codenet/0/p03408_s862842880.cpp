#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        char s[205][50];
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        scanf("%d",&m);
        getchar();
        for(int i=n;i<m+n;i++)
        {
            scanf("%s",s[i]);
        }
       /** for(int i=0;i<m+n;i++)
        {
            printf("%s\n",s[i]);
        }*/
        int d=0;
        int shu[205];
        for(int i=0;i<205;i++)
            shu[i]=300;
        for(int i=0;i<n+m;i++)
        {
            for(int j=1;j<n+m;j++)
            {
                if(strcmp(s[i],s[j])==0&&shu[j]==300)
                    shu[i]=shu[j]=d;
            }
            d++;
        }
        int maxn[100],maxs=-100;
        for(int i=0;i<n;i++)
        {
            int x=1;
            for(int j=1;i<n+m;j++)
            {
                if(j<n)
                {
                    if(shu[i]==shu[j])
                    {
                        x++;
                    }
                }
                if(j>=n)
                {
                    if(shu[i]==shu[j])
                    {
                        x--;
                    }
                }
                maxn[i]=x;
                if(maxn[i]>maxs)
                    maxs=maxn[i];
            }
        }
        printf(maxs>0?"%d\n":"0\n",maxs);
    }
    return 0;
}

