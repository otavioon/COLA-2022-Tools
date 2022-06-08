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
        int s,t;
        if(j)
        {
            s=0;
            t=a[j];
            for(i=1;i<=n;i++)
            {
                if(a[t]==2)
                {
                    s++;
                    break;
                }
                else
                {
                    t=a[t];
                    s++;
                }
            }
             if(i<=n)
            {
                printf("%d\n",s);
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            s=1;
            t=a[1];
            for(i=1;i<=n;i++)
            {
                if(a[t]==2)
                {
                    s++;
                    break;
                }
                else
                {
                    t=a[t];
                    s++;
                }
            }
            if(i<=n)
            {
                printf("%d\n",s);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}
