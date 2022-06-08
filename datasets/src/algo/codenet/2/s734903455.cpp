#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>

using namespace std;
int main()
{
    long long N;
    cin >> N;
    std::multiset<long long> v;
    std::multiset<long long> pow2;

    for (long long i = 2; i < 10e12; i *= 2)
    {
        pow2.insert(i);
    }

    for (long long i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        v.insert(tmp);
    }

    //sort(v.begin(), v.end());
    //v.sort();

    long long ans = 0;

    /*
    std::cout
        << std::boolalpha
        << std::binary_search(v.begin(), v.end(), 3, greater<long long>())
        << std::endl;
        */

    while (v.size() >= 2)
    {
        long long pairOne = *v.rbegin();
        v.erase(v.find(pairOne));
        long long pairTwo;

        auto iterPow2 = upper_bound(pow2.begin(), pow2.end(), pairOne);
        pairTwo = *iterPow2 - pairOne;

        auto iterTwo = v.find(pairTwo);
        if (iterTwo != v.end())
        {
            v.erase(iterTwo);
            ans++;
        }
    }

    cout << ans << endl;
}