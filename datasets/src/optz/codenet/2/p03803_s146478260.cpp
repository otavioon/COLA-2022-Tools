#include <iostream>
using namespace std;

struct edge {
	int s;
	int e;
};
struct ver {
	int num;
	bool visted = 0;
};
edge inedge[100];
ver inver[15];
int ans = 0;
int N, M;

void path(int get, int count) {
	++count;
	inver[get].visted = 1;
	if (count == N)
		ans++;
	else {
		for (int i = 1;i <= M;++i) {
			if (inedge[i].s == get && !(inver[inedge[i].e].visted) && !(inver[inedge[i].s].visted))
				path(inedge[i].e, count);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= M;++i)
		cin >> inedge[i].s >> inedge[i].e;
	for (int i = 1;i <= N;++i) {
		inver[i].num = i;
		inver[i].visted = 0;
	}
	path(inedge[1].s, 0);
	cout << ans << endl;
	//system("pause");
	return 0;
}