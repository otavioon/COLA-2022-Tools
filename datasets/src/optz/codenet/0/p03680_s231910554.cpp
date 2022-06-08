#include<iostream>
using namespace std;
int main()
{
    int n,a[100000],i,k;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];

    k=1;
    int d=0;
    int t;
    for(i=1;a[i]!=2; i=a[i])
    {
        k++;
        if(a[i]==1)
        {
            d++;
            break;
        }
    }
    if(d>0)
        k=-1;

    cout<<k<<endl;

}
