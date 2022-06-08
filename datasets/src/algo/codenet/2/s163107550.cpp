#include <bits/stdc++.h>

#define int long long
#define mod 1000000007

using namespace std;

int a[200010];

int32_t main()
{
    int n;
    cin >> n;

    multiset <int> s;

    for(int i=0;i<n;i++)
        cin >> a[i], s.insert(a[i]);

    int count = 0;

    while(!s.empty())
    {
        int temp = *(--s.end());

        int cnt = 1;

        while(cnt <= temp)
            cnt *= 2;

        s.erase(--s.end());

        if(cnt != temp)
        {
            cnt -= temp;

            if(s.find(cnt) != s.end())
            {
                count++;
                s.erase(s.find(cnt));
            }
        }
    }

    cout << count << endl;
}