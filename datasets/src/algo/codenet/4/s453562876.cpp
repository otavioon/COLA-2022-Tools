#include<bits/stdc++.h>
using namespace std;

bool ok(int n, set<int>& s)
{
    while(n > 0)
    {
        int tmp = n%10;
        n/=10;
        if(s.find(tmp) != s.end()) return false;
    }
    return true;
}

int main()
{
    int n,k;
    cin >> n >> k;
    set<int> d;
    for(int i=0; i<k; ++i) 
    {
        int x;
        cin >> x;
        d.insert(x);
    }
    for(int i=n; i<=100000; ++i)
    {
        if(ok(i,d)) 
        {
            cout << i <<"\n";
            break;
        }
    }
    return 0;
}