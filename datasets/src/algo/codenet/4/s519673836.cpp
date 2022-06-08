#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    set<int>s;
    for(int i = 0; i < k; ++i)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    
    for(int j = n; j <= INT_MAX; ++j)
    {
        int t = j;
        while(t)
        {
            if(s.count(t % 10) == 1)
            {
                break;
            }
            t /= 10;
        }
        
        if(t == 0)
        {
            cout << j << endl;
            break;
        }
    }
    
    return 0;
}