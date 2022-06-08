#include <iostream>
#include <cstdio>
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(A[i]<B[j]&&B[j]<C[k])
                {
                    sum=sum+n-k;
                    break;
                }

            }
        }
    }
    printf("%d\n",sum);

    return 0;
}
