#include <iostream>
#include <cstdio>
#include<cstring>
#include <algorithm>
#include <cmath>
typedef  long long LL;
using namespace std;
const int N=1e5+5;
int main()
{
    int n;
    scanf("%d",&n);
    int A[N],B[N],C[N];

  //  memset(A,0,sizeof(0))

    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&B[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&C[i]);

    sort(A,A+n);
    sort(B,B+n);
    sort(C,C+n);
    int sum=0;

    int st1=0,st2=0;
    for(int i=0;i<n;i++)
    {
       // if()

        for(;B[i]>A[st1];st1++)
        {
            if(B[i]>A[n-1])
            {
                st1=n;break;
            }
         //   if(st1>=n) break;
        }
       // printf("st1111=%d\n",st1);
       for(;B[i]>=C[st2];st2++)
       {
           if(B[i]>=C[n-1])
            {
                st2=n;break;
            }
         //  if(st2>=n) break;
       }

   //   printf("%d  %d  %d\n",st1,st2,st1*(n-st2));

        sum+=st1*(n-st2);
    }

    printf("%d\n",sum);

    return 0;
}
