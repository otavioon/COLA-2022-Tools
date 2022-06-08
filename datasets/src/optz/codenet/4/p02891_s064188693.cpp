#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

long long k;
int n;
string s;

void nhap()
{
    cin>>s>>k;
    n=s.length();
}

void process()
{
    long long t=0,vt=0,f=0;
    while (vt<n)
    {
        int dem=1;
        while (vt<n-1 && s[vt]==s[vt+1])
        {
            vt++;
            dem++;
        }
        t+=dem/2;
        vt++;
    }
    if (s[n-1]==s[0])
    {
        long long d1=1,d2=1;
        for (int i=1;i<n;++i)
        {
            if (s[i]==s[i-1]) d1++;
            else break;
        }
        for (int i=n-2;i>=0;--i)
        {
            if (s[i]==s[i+1]) d2++;
            else break;
        }
        if (d1%2==1 && d2%2==1)
        {
            t++;
            f=1;
        }
    }
    cout<<t*k-f;
}

int main()
{
    nhap();
    process();
    return 0;
}
