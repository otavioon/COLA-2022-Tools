#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

/////////////		グラフを扱うクラス

class edgeClass {// 辺のクラス
public:
	edgeClass() {
		x = 0, y = 0, weight = 1;
	}
	void swap() {
		int c = x;
		x = y;
		y = c;
	}
	int x, y, weight;
};
bool edgeClass_compare(const edgeClass& a, const edgeClass& b) {// keyを見比べる
	int x = b.x - a.x;
	if (x > 0) { return true; }
	x = b.y - a.y;
	return x > 0;
}
class graphClass {// グラフ入力を受け取る
public:
	graphClass() {
		N = 0;
		M = 0;
		next = NULL;
		edge.clear();
		weight = NULL;
		directedFlag = false;
	}

	void activate(int n, bool directed = false) {// 頂点数nのグラフを初期化する。
		directedFlag = directed;
		N = n;
		M = 0;
		edge.clear();
		if (next != NULL) { delete[] next; }
		if (weight != NULL) { delete[] weight; }
		next = new vector<edgeClass>[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) { weight[i] = 1; }
	}
	void setNodeWeight(int n, int weight) {// n番のノードの重みをweightに設定
		this->weight[n] = weight;
	}
	void addEdge(int x, int y, int weight = 1) {// エッジ追加
		edgeClass e;
		e.x = x;
		e.y = y;
		e.weight = weight;

		if (e.x < 0 || e.x >= N) { return; }

		edge.push_back(e); M++;
		next[e.x].push_back(e);

		if (directedFlag == false) {
			e.swap();
			next[e.x].push_back(e);
		}

	}
	void sortEdge() {// 各ノードについて、接続先の番号を昇順ソート
		for (int i = 0; i < N; i++) {
			if (next[i].size() > 1) {
				sort(next[i].begin(), next[i].end(), edgeClass_compare);
			}
		}
	}

	bool isTree() {// 木になっているかどうか幅優先探索で調べる
		if (N <= 0 || M != N - 1) { return false; }

		bool* visited = new bool[N];
		for (int i = 0; i < N; i++) {
			visited[i] = (i == 0);
		}

		queue<int> q; q.push(0);

		while (q.size() > 0) {
			int n = q.front(); q.pop();
			visited[n] = true;

			for (auto itr = next[n].begin(); itr != next[n].end(); itr++) {
				if (visited[itr->y] == false) {
					q.push(itr->y);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (visited[i] == false) { delete[] visited; return false; }
		}

		delete[] visited;
		return true;
	}

	long* dijkstra(int n) {// ダイクストラ法で始点nからの最短距離を得る
		if (n < 0 || n >= N) { return NULL; }

		long* buf = new long[N];
		for (int i = 0; i < N; i++) {
			buf[i] = 1001001001;
		}

		// 昇順に出力
		// pair<重み, 番号>を並べておく
		priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;

		buf[n] = 0;
		q.push(pair<long, int>(0, n));

		while (q.empty() == false) {
			pair<long, int> p = q.top(); q.pop();
			int k = p.second;
			if (p.first <= buf[k]) {
				for (auto itr = next[k].begin(); itr != next[k].end(); itr++) {
					if (buf[itr->y] > buf[k] + (long)itr->weight) {
						buf[itr->y] = buf[k] + (long)itr->weight;
						q.push(pair<long, int>(buf[itr->y], itr->y));
					}
				}
			}
		}

		return buf;
	}

	long* bellmanFord(int n) {// ベルマンフォード法で始点nからの最短距離を得る
		if (n < 0 || n >= N) { return NULL; }

		long* buf = new long[N];
		for (int i = 0; i < N; i++) {
			buf[i] = 1001001001;
		}
		buf[n] = 0;
		for (int i = 0; i < N; i++) {
			for (auto itr = edge.begin(); itr != edge.end(); itr++) {
				if (buf[itr->y] > buf[itr->x] + (long)(itr->weight)) {
					buf[itr->y] = buf[itr->x] + (long)(itr->weight);
					if (i == N - 1) {
						return NULL;
					}
				}
			}
		}
		return buf;
	}

	long* getDistanceFrom(int n) {
		if (n < 0 || n >= N) { return NULL; }

		bool negativeFlag = false;
		for (auto itr = edge.begin(); itr != edge.end(); itr++) {
			if (itr->weight < 0) {
				negativeFlag = true;
				break;
			}
		}
		if (negativeFlag) {// 負の重みがあればベルマンフォード法
			return bellmanFord(n);
		}
		else {// 全て非負ならダイクストラ法
			return dijkstra(n);
		}
	}

	long** getDistanceTable() {// 最短距離の表を受け取る。対角成分に非ゼロが含まれていたら、重み負の閉路が存在している。

		long** buf = new long* [N];
		for (int i = 0; i < N; i++) {
			buf[i] = new long[N];
			for (int j = 0; j < N; j++) {
				buf[i][j] = 1000000000;
			}
			buf[i][i] = 0;
		}

		bool flag = true;
		for (auto itr = edge.begin(); itr != edge.end(); itr++) {
			if (itr->weight < 0) { flag = false; break; }
		}
		if (flag) {// 全て0以上だったらダイクストラ法を使う
			for (int i = 0; i < N; i++) {
				long* d = getDistanceFrom(i);
				for (int j = 0; j < N; j++) {
					buf[i][j] = d[j];
				}
				delete[] d;
			}

		}
		else {// 負の重みが含まれていたらワーシャルフロイド法を使う
			for (int i = 0; i < N; i++) {
				for (auto itr = next[i].begin(); itr != next[i].end(); itr++) {
					buf[i][itr->y] = itr->weight;
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						buf[j][k] = min(buf[j][k], buf[j][i] + buf[i][k]);
					}
				}
			}
		}
		return buf;
	}

	void debugCout() {// デバッグ出力用
		cout << endl;
		cout << "ノードの個数 = " << N << "個" << endl;
		cout << "エッジの本数 = " << M << "本" << endl;
		cout << endl;

		for (int i = 0; i < N; i++) {
			cout << "i = " << i << " (weight = " << weight[i] << "), 接続先 = ";
			if (next[i].size() == 0) { cout << "なし" << endl; continue; }
			auto itr = next[i].begin();
			cout << itr->y << "(weight = " << itr->weight << ")";
			itr++;

			for (; itr != next[i].end(); itr++) {
				cout << ", " << itr->y << "(weight = " << itr->weight << ")";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool directedFlag;// 有向グラフかどうか
	int N, M;
	int* weight;// ノードの重み
	vector<edgeClass>* next;// 各ノードにおける辺
	vector<edgeClass> edge;// エッジ
};



void bfs(graphClass& G, int root) {// 幅優先探索
	int N = G.N;
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++) {
		visited[i] = (i == root);
	}

	queue<int> q; q.push(root);

	while (q.size() > 0) {
		int n = q.front(); q.pop();
		visited[n] = true;

		// ここに各ノードで行う処理を書く

		for (auto itr = G.next[n].begin(); itr != G.next[n].end(); itr++) {

			// ここに各エッジで行う処理を書く

			if (visited[itr->y] == false) {// まだ訪れていなかったら
				q.push(itr->y);
			}
		}
	}

	delete[] visited;
}

long* counter = NULL;

bool* dfs_visited = NULL;
void dfs_process_main(graphClass& G, int n, long V) {// 深さ優先探索
	dfs_visited[n] = true;

	V += G.weight[n];
	counter[n] = V;

	// ここに各ノードで行う処理を書く

	for (auto itr = G.next[n].begin(); itr != G.next[n].end(); itr++) {

		// ここに各エッジで行う処理を書く

		if (dfs_visited[itr->y] == false) {// まだ訪れていなかったら
			dfs_process_main(G, itr->y, V);
		}
	}
}
void dfs(graphClass& G, int root) {// 深さ優先探索
	int N = G.N;
	dfs_visited = new bool[N];
	for (int i = 0; i < N; i++) { dfs_visited[i] = false; }
	dfs_process_main(G, 0, 0);

	delete[] dfs_visited;
	dfs_visited = NULL;
}

int main() {
	int N, Q; cin >> N >> Q;
	graphClass G; G.activate(N);

	counter = new long[N];
	for (int i = 0; i < N; i++) {
		counter[i] = 0;
		G.weight[i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		G.addEdge(a - 1, b - 1);
	}

	for (int i = 0; i < Q; i++) {
		int p, x; cin >> p >> x;
		G.weight[p - 1] += x;
	}

	dfs(G, 0);

	for (int i = 0; i < N; i++) {
		cout << counter[i] << " ";
	}
	cout << endl;

	return 0;
}
