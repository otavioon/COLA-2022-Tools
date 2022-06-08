#include <bits/stdc++.h>
using namespace std;

int getDigit(int i)
{
    int ans = 0;

    while(i != 0)
    {
        i /= 10;
        ++ans;
    }
    return ans;
}

int main(void)
{
    int N, K;

    cin >> N >> K;

    vector<int> D(K, 0);
    for(int i = 0; i < K; ++i)
    {
        cin >> D[i];
    }
    std::sort(D.begin(), D.end());

    int s;
    for(s = N; ; ++s)
    {
        int st = s;
        bool ok = true;
        for(int i = 0; st != 0; ++i)
        {
            if(std::binary_search(D.begin(), D.end(), st%10))
            {
                ok = false;
                break;
            } 
            st /= 10;
        }
        if(ok) break;
    }


    cout << s << endl;

    return 0;
}

