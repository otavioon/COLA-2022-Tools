#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> v;
vector <int> beginnings, endings;
vector <int> seg[800200];

void build_tree(int node, int a, int b){
    if(a == b){
        seg[node].push_back(endings[a]);
        return;
    }
    int m = (a + b)/2;
    build_tree(2*node, a, m), build_tree(2*node + 1, m + 1, b);
    merge(seg[2*node].begin(), seg[2*node].end(), seg[2*node + 1].begin(), seg[2*node + 1].end(), back_inserter(seg[node]));
}

int query(int node, int a, int b, int l, int r, int v){
    if(a > r || b < l)  return 0;
    if(l <= a && b <= r){
      return upper_bound(seg[node].begin(), seg[node].end(), v) - seg[node].begin();
    }
    int m = (a + b)/2;
    return query(2*node, a, m, l, r, v) + query(2*node + 1, m + 1, b, l, r, v);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, q, l, r, a, b;
    cin >> n >> m >> q;
    v.resize(m), beginnings.resize(m), endings.resize(m);
    for(int i = 0; i < m; ++i)  cin >> v[i].ff >> v[i].ss;
    sort(v.begin(), v.end()); 
    for(int i = 0; i < m; ++i)  beginnings[i] = v[i].ff, endings[i] = v[i].ss;
    build_tree(1, 0, m - 1);

    for(int i = 0; i < q; ++i){
        cin >> l >> r;
        a = (lower_bound(beginnings.begin(), beginnings.end(), l) - beginnings.begin());
        b = (upper_bound(beginnings.begin(), beginnings.end(), r) - beginnings.begin()) - 1;
            cout << query(1, 0, m - 1, a, b, r) << "\n";
    }

    return 0;
}