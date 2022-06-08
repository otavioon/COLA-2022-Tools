#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct node {
    int parent;
    vector<int> child;
    int counter = 0;
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> ab(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    vector<node> tree(N);
    for (int i = 0; i < N - 1; i++) {
        tree[ab[i].first - 1].child.push_back(ab[i].second);
        tree[ab[i].second - 1].parent = ab[i].first;
    }

    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        tree[p - 1].counter += x;
    }

    for (int i = 0; i < N; i++) {
        int counter = tree[i].counter;
        for (int j = 0; j < tree[i].child.size(); j++) {
            tree[tree[i].child[j] - 1].counter += counter;
        }
        cout << counter << " ";
    }
    cout << endl;

    return 0;
}
