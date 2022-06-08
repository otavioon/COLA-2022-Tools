/***
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 *      百年修得同船渡，千年修得代码重.
 */
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
//int n,m,x,y;
//char a[1010][1010];
//int vis[1010][1010];
//void dfs()
//{
//
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        for(int i=0;i<n;i++)
//        scanf("%s",a[i]);
//        for(int i=0;i<n;i++)
//            for(int j=0;j<m;j++)
//        {
//            if(a[i][j]=='*')
//                vis[i][j]=2;
//                if(a[i][j]=='+')
//                    vis[i][j]=1;
//                if(a[i][j]=='F')
//                    vis[i][j]=3;
//                if(a[i][j]=='G')
//                {
//                    x=i;
//                    y=j;
//                }
//                if(i==0&&a[i][j]=='+')
//                    vis[i][j]=4;
//                if(i==n&&a[i][j]=='+')
//                    vis[i][j]=4;
//                if(j==0&&a[i][j]=='+')
//                    vis[i][j]=4;
//                if(j==m&&a[i][j]=='+')
//                    vis[i][j]=4;
//
//        }
//
//     for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<m;j++)
//                printf("%d ",vis[i][j]);
//                printf("\n");
//            }
// }
//    return 0;
//}
long long  a[100010];
long long  b[100010];
long long  c[100010];
long long ans;
int n;
int f()
{
    for(int i=0;i<n;i++)
    {long long zz=0;
    long long xx=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]<b[i])
                zz++;
            else
                break;
        }
        for(int j=n-1;j>=0;j--)
        {
            if(b[i]<c[j])
                xx++;
                    else
                    break;
        }
        ans=ans+xx*zz;
    }
    return ans;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%lld",&b[i]);
        for(int i=0;i<n;i++)
            scanf("%lld",&c[i]);
            sort(a,a+n);
            sort(b,b+n);
            sort(c,c+n);
            ans=0;
        f();
        printf("%lld\n",ans);
    }

    return 0;
}


