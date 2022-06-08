#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin>>s;
    long long int k; cin>>k;
    int ile=0;
    int n=s.length();
    bool ok =false;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            ile++;
            if(i==n-1)
            {
                ok = true;
            }
            i++;
        }
    }
    if(s[0]==s[n-1] && ok == false) ile++;
    cout<<k*ile;
    return 0;
}
