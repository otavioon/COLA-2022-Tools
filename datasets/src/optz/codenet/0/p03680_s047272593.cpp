#include <iostream>
#include <cstdio>

using namespace std;

int a[50000];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)
            {
                j=i;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(a[a[i]]==i)
            {
                printf("-1\n");
                return 0;
            }
        }
        int s,t;
        if(j)
        {
            s=1;
            t=a[j];
            for(i=1;i<=n;i++)
            {
                if(a[t]==2)
                {
                    break;
                }
                else
                {
                    t=a[t];
                    s++;
                }
            }
        }
        else
        {
            s=0;
            t=a[0];
            for(i=1;i<=n;i++)
            {
                if(a[t]==2)
                {
                    break;
                }
                else
                {
                    t=a[t];
                    s++;
                }
            }
            s=s-2;
        }
        printf("%d\n",s);
    }
    return 0;
}
