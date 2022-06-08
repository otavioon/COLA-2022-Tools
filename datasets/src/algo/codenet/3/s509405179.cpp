#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

long long N;
long long a[100010];
long long b[100010];
long long c[100010];
long long n,m,sum=0;
int main()
{
    scanf("%lld",&N);
    for(int i=0; i<N; i++)
        scanf("%lld",&a[i]);
    for(int i=0; i<N; i++)
        scanf("%lld",&b[i]);
    for(int i=0; i<N; i++)
        scanf("%lld",&c[i]);
    sort(a,a+N);
    sort(b,b+N);
    sort(c,c+N);
    for(int i=0; i<N; i++)
    {
        for(int j=N-1; j>=0; j--)
        {
            if(a[i]<b[j])
            {
                for(int k=N-1; k>=0; k--)
                {
                    if(b[j]<c[k])
                        sum++;
                }
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}
