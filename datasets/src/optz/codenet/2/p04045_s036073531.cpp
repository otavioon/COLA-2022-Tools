#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
using Graph = vector<vector<string>>;

void dfs(const Graph &G, vector<int> &pattern, int N, int depth, string value)
{
    if (depth == G.size()) {
        if (stoi(value) >= N) pattern.push_back(stoi(value));
        return;
    }
    for (auto next_value : G[depth]) {
        dfs(G, pattern, N, depth+1, value+next_value);
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

    vector<int> pattern(10000);
    dfs(G, pattern, N, 0, "");
    pattern.erase(unique(pattern.begin(), pattern.end()), pattern.end());

    cout << pattern[1] << endl;
}