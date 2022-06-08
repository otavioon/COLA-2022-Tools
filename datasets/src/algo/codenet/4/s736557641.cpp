#include <bits/stdc++.h>
using namespace std;
set<int>s;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int temp;
    for(int i=0;i<k;i++)
    {
        cin>>temp;
        s.insert(temp);
    }
    for(int j=n;j<=INT_MAX;j++)
    {
        int t=j;
        while(t)
        {
            if(s.count(t%10)==1)
            {
                break;
            }
            t=t/10;
        }
        if(t==0)
        {
            cout << j <<endl;
            break;
        }
    }
    return 0;
}
