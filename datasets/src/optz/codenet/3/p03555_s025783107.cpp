#include<bits/stdc++.h>

#define _ cin.tie(0);ios::sync_with_stdio(false);
using namespace std;

#define rep(n) for(int i = 0; i < n; i++)
#define Sort(a) sort(a.begin(), a.end())
using LL = long long;
const int N = 100000 + 5;

LL tree[N];
LL Query(int pos){
    LL sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

void Add(int pos,LL num){
    while(pos <= N){
        tree[pos] += num;
        pos += (pos & -pos);
    }
}
vector<LL> a, b, c;
int main(){ _
    LL  n, m;
    memset(tree, 0, sizeof(tree));
    cin >> n;
    rep(n) { cin >> m; a.push_back(m); }
    rep(n) { cin >> m; b.push_back(m); }
    rep(n) { cin >> m; c.push_back(m); }
    Sort(a), Sort(b), Sort(c);

    for(int i = 0; i < n; i++){
        auto tmp = lower_bound(a.begin(), a.end(), b[i]);
        int num = tmp - a.begin();
        Add(i + 1, num);

    }
    LL sum = 0;
    for(auto &i : c){
        auto tmp = lower_bound(b.begin(), b.end(), i);
        int cur = tmp - b.begin();
        LL num = Query(cur);
        sum += num;
    }
    /**
    LL sum = 0;
    rep(n){
        LL A = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        LL B = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        sum += (A * B);
    }*/
    cout << sum << endl;
}