#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long n;
    int i,m,l;
    cin>>n;
    int ans=0,tot=0;
    for(i=sqrt(n);i>=0;i--){
        if(n%i==0){
            m=n%i;
            if(m>=10)
            {
                m/=10;
                ans++;
            }
        }
    }
    tot=max (ans,tot);
    cout<<tot;
    cout<<endl;
    return 0;
}