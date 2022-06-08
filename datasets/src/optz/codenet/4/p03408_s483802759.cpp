#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<string> dict;
set<string> ldict;

int main()
{
    int n,i,m,s,q,w,t;
    string a[102];
    string b[102];
    int sum1[102];
    int sum2[102];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        dict.insert(a[i]);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>b[i];
        ldict.insert(a[i]);
    }
    s=0;
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==(*it))
            {
               sum1[s]++;
            }
        }
        s++;
    }
    t=0;
    for(set<string>::iterator it=ldict.begin();it!=ldict.end();it++)
    {
        for(i=0;i<n;i++)
        {
            if(b[i]==(*it))
            {
                sum2[t]++;
            }
        }
        t++;
    }
    q=0;
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++,q++)
    {
         w=0;
         for(set<string>::iterator it1=ldict.begin();it1!=ldict.end();it1++,w++)
         {
            if(*it==*it1)
            {
                sum1[q]=sum1[q]-sum2[w];
            }
         }
    }
    sort(sum1,sum1+s);
    if(sum1[s-1]>0)
    {
        printf("%d\n",sum1[s-1]);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
