#include <iostream>

using namespace std;
long long n,s,i,x,a[1000000];
int main()
{
    cin >> n;
    for (i=1; i<n; i++)
        cin >> a[i];
 
    for (i=2; i<n-1; i++)
    if (a[i]>a[i-1] && a[i]>a[i+1] && i==2)
    a[i]=max(a[i-1],a[i+1]);
    else
    if (a[i]>a[i-1] && a[i]>a[i+1])
    a[i]=min(a[i-1],a[i+1]);
    
    for (i=1; i<n; i++)
    s+=a[i];
    if (n>2)
    cout<<s;
    else
   cout<<s+a[1];

    return 0;
}
