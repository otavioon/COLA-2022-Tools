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
        int x1,maxs=-100;
        for(int i=0;i<n;i++)
        {
            int x=1;
            for(int j=1;i<n+m;j++)
            {
                if(j<n)
                {
                    if(strcmp(s[i],s[j])==0)
                    {
                        x++;
                    }
                }
                if(j>=n)
                {
                    if(strcmp(s[i],s[j])==0)
                    {
                        x--;
                    }
                }
            }
            x1=x;
            if(x1>maxs)
                maxs=x1;
        }
        printf(maxs>0?"%d\n":"0\n",maxs);
    }
    return 0;
}

