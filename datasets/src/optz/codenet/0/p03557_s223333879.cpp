#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int i,k;
    int n;
    vector <long> ::iterator up;

    scanf("%d",&n);

    long a[n],b[n],c[n];
    long d[n];
    long x;
    long long sum=0;

    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);    //!!!
    for(i=0;i<n;i++)
        scanf("%ld",&b[i]);    //!!!
    for(i=0;i<n;i++)
        scanf("%ld",&c[i]);    //!!!
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    vector <long> bb(b,b+n),cc(c,c+n);
    for(k=0;k<n;k++)
        d[k]=cc.end()-upper_bound(cc.begin(),cc.end(),b[k]);
    for(i=0;i<n;i++){
        up=upper_bound(bb.begin(),bb.end(),a[i]);
        for(k=up-bb.begin();k<n;k++){
            sum+=d[k];
        }
    }

    printf("%lld",sum);

    return 0;
}
