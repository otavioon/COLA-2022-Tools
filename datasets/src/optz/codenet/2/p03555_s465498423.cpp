#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long a[n],b[n],c[n],a1[n],b1[n],c1[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];    
    }
    for(long long j=0;j<n;j++)
    {
            cin>>b[j];
    }
    for(long long j=0;j<n;j++)
    {
            cin>>c[j];
    }
    sort(a,a+n);sort(b,b+n);sort(c,c+n);
    for(long long i=0;i<n;i++)
    {
       
        
        if(i==0)
        { a1[i]=0;
            long long cz=0;
            while(b[i]>a[cz])
            {
                cz++;a1[i]++;
            }
        }
        else
        { a1[i]=a1[i-1];
            long long cz=a1[i-1];
             while(b[i]>a[cz])
            {
                cz++;a1[i]++;
            }
        }
    }
    for(long long i=0;i<n;i++)
    {
       
        
        if(i==0)
        { b1[i]=0;
            long long cz=0;
            while(c[i]>b[cz])
            {
                cz++;b1[i]++;
            }
        }
        else
        { b1[i]=b1[i-1];
            long long cz=b1[i-1];
             while(c[i]>b[cz])
            {
                cz++;b1[i]++;
            }
        }
    }
    long long ans=0;
    
     for(long long i=0;i<n;i++)
    {
       if(i==0)
       {
           c1[i]=a1[i];
       }
       else{
           c1[i]=c1[i-1]+a1[i];
       }
    }
    for(long long i=0;i<n;i++)
    {
        long long h=b1[i]-1;
       if(h>=0)ans+=c1[h];
    }
    cout<<ans;
    return 0;
}
