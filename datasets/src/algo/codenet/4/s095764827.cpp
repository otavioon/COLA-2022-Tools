#include <bits/stdc++.h>
using namespace std;

void find(int &n,vector<bool> &h)
{
    int x;
    if(h.at(n%10)==1)
    x=1;
    else if (n>=10&&h.at(n%100/10)==1)
    x=10;
    else if(n>=100&&h.at(n%1000/100)==1)
    x=100;
    else if(n>=1000&&h.at(n%10000/1000)==1)
    x = 1000;
    else if(n>=10000&&h.at(n/10000)==1)
    x =10000;
    else 
    return;

    for (n;1;n+=x)
    {
        if(h.at(n%(10*x)/x)==0)
        break;
    }
    find(n,h);
}

int main ()
{
    int n,k;
    cin >>n>>k;
    vector<bool> h(10,0);
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        h.at(a)=1;
    }
    find(n,h);
    cout<<n<<endl;
}