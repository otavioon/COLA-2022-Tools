#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int ctoi(char);

struct btn{
    int next;
    int flag;
};

int main()
{
    int N,M;
    vector<string> blue, red;

    cin >> N;
    rep(i, N)
    {
        string s;
        cin >> s;
        blue.push_back(s);
    }
    cin >> M;
    rep(i, M)
    {
        string s;
        cin >> s;
        red.push_back(s);
    }

    int ans = 0;
    rep(i, N)
    {
        string kw = blue.at(i);
        int count = 1;
        rep2(j, i+1, N)
        {
            if (kw == blue.at(j))
            {
                count++;
            }
        }
        rep(l, M)
        {
            if (kw == red.at(l))
            {
                count --;
            }
            if (count == 0) break;
        }
        if (ans < count) ans = count;
    }
    cout << ans << endl;
}


int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c -'0';
    }
    return -1;
}
