#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long LL;
const int MAXN = 2*100000;
int N, Q, ans, score[MAXN], cnt[MAXN];
vector<vector<int> > mapp(MAXN);

void dfs(int u, int p) {

    if(p != -1){
        score[u] = score[p]+score[u];
    }

    for(int i = 0; i < mapp[u].size(); i++){

        if(mapp[u].at(i) == p){
            continue;
        }
        dfs(mapp[u].at(i),u);
    }

}


int main() {

    memset(cnt, 0, sizeof(cnt));//点数をリセット
    memset(score, 0, sizeof(score));//追加するスコア情報
    cin >> N >> Q;

    for(int i = 0; i < N - 1; i++){
        int tmp1, tmp2;
        vector <int > v_tmp;
        cin >> tmp1 >>tmp2;
        tmp1--;
        tmp2--;
        mapp[tmp1].push_back(tmp2);
        mapp[tmp2].push_back(tmp1);
    }

    for(int i = 0; i < Q; i++){
        int tmp1, tmp2;
        cin >> tmp1 >>tmp2;
        tmp1--;
        score[tmp1] += tmp2;
    }

    dfs(0,-1);

    for(int i = 0; i < N; i++){
        cout << score[i] << endl;
    }
	return 0;
}

