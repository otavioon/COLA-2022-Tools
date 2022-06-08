#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
using Graph = vector<vector<string>>;

void dfs(const Graph &G, set<int> &set, int N, int depth, string value)
{
    if (depth == G.size()) {
        if (stoi(value) >= N) set.insert(stoi(value));
        return;
    }
    for (auto next_value : G[depth]) {
        dfs(G, set, N, depth+1, value+next_value);
    }
}

int main()
{
    int N, K; cin >> N >> K;
    vector<string> D(9);
    rep (i, 0, K) {
        string in; cin >> in;
        D.push_back(in);
    }
    vector<string> vec;
    rep (i, 0, 10) {
        auto iter = find(D.begin(), D.end(), to_string(i));
        bool found = iter != D.end();
        if (found) continue;
        vec.push_back(to_string(i));
    }
    Graph G(4);
    rep (i, 0, 4) {
        copy(vec.begin(), vec.end(), back_inserter(G[i]));
    }

    set<int> set;
    rrep (i, 0, G.size()) {
        dfs(G, set, N, i, "0");
    }

    for (auto num : set) {
        cout << num << endl;
        return 0;
    }
}