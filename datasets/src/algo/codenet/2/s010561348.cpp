#include <bits/stdc++.h>
using namespace std;

multiset<int> se;

int main()
{
    // freopen("powers.in", "r", stdin);
    // freopen("powers.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        se.insert(x);
    }
    int answer = 0;
    while (!se.empty())
    {
        multiset<int>::iterator it = se.end();
        it--;
        int back = *it;
        se.erase(it);
        int i = 1;
        for (; i <= back; i <<= 1)
            ;
        if (se.find(i - back) != se.end())
        {
            se.erase(se.find(i - back));
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}
