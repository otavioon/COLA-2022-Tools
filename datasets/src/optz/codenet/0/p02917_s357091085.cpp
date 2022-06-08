#include <bits/stdc++.h>
using namespace std;

void main_()
{
    int N;
    cin >> N;
    vector<int> Bs;
    copy_n(istream_iterator<int>(cin), N - 1, back_inserter(Bs));
    vector<int> As;
    As.push_back(Bs.front());
    transform(
        begin(Bs), end(Bs) - 1,
        begin(Bs) + 1, back_inserter(As),
        [](int n1, int n2) { return min(n1, n2); });
    As.push_back(Bs.back());

    cout << accumulate(begin(As), end(As), 0) << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
