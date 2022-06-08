#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// ctrl + option + N : 実行

#define MAX 200005
#define NIL -1
struct Node {int parent , left, right, count;};
Node Tree[MAX];
int n, q, queries[MAX];

void setCount(int id, int add){
    Tree[id].count += add;
    if (Tree[id].right != NIL) setCount(Tree[id].right, add);
    if (Tree[id].left != NIL) setCount(Tree[id].left, add + queries[Tree[id].left]);

}

void setChild(int id, int target){
    if ( Tree[id].left == NIL) Tree[id].left = target;
    else if (Tree[id].right == NIL) Tree[id].right = target;
    else setChild(Tree[id].right, target);
    Tree[target].parent = id;
}

int main() {
    cin >> n >> q;
    // Tree を初期化
    rep(i, n+1) {
        Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
        Tree[i].count = 0;
    }

    // Queries を初期化
    rep(i, q) {
        queries[i] = 0;
    }
    int id, target;
    // input: [id, target]
    rep(i, n-1) {
        cin >> id >> target;
        setChild(id, target);
    }

    // input: [id, add]
    int qid, add;
    rep(i, q){
        cin >> qid >> add;
       queries[qid] += add; 
    }

    setCount(1, queries[1]);

/**
rep(i, n){
    cout << i << "query: " << queries[i] << endl;
}
rep(i, n+1){
    if (i != 0)cout << Tree[i].count << Tree[i].parent << Tree[i].left << Tree[i].right << endl;
}
*/
    for(int i=1; i < n+1; i++){
        if (i != 1) cout << " ";
        cout << Tree[i].count;
        if(i == n) cout << endl;
    }
    return 0;
}