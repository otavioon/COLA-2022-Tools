#include <bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define mp make_pair
typedef long long ll;
typedef pair<int,int> iPair;

vector<int>* tree;
int* lazy;

void dfs(int curr, int prev) {
  for(auto x : tree[curr]) {
    if(x == prev) continue;
    lazy[x] += lazy[curr];
    dfs(x, curr);
  }
}

int main() {
  int N,Q;
  scanf("%d%d", &N, &Q);
  
  tree = new vector<int>[N];
  lazy = new int[N];
  memset(lazy, 0, N*sizeof(int));

  FOR(i,N-1) {
    int a,b;
    scanf("%d%d", &a, &b);
    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
  }

  FOR(i,Q) {
    int a,b;
    scanf("%d%d", &a, &b);
    lazy[a-1] += b;
  }

  dfs(0, -1);
  FOR(i,N) cout << lazy[i] << ' ';
}
