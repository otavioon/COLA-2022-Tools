#include <bits/stdc++.h>
using namespace std;
bool check(int n,vector<int>a)
{
      while(n>0)
    {
        int temp=n%10;
        if(a[temp])
        {
            return false;
        }
        n=n/10;
    }
    return true;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(10);
    for(int i=0;i<k;i++)
    {
        int f;
        cin>>f;
        a[f]=1;
    }
    for(int i=n;i<=1000000000;i++)
    {
        if(check(i,a))
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;

   
}
