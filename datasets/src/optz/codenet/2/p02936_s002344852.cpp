#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    uint32_t val;
    vector<TreeNode *> next;
    TreeNode() : val(0){}
};


void treeNodeAdd(TreeNode *t, uint32_t val)
{
    t->val += val;
    for (TreeNode *tn : t->next) {
        treeNodeAdd(tn, val);
    }
}

int main(int argc, const char * argv[]) {
    uint32_t N, Q;
    cin >> N;
    cin >> Q;
    
    // 初期化。
    vector<TreeNode> t;
    for (uint32_t i = 0; i < N; i++) {
        TreeNode tmp;
        t.push_back(tmp);
    }
    
    // ノードをつなげる。
    for (uint32_t i = 0; i < N - 1; i++) {
        uint32_t a,  b;
        cin >> a;
        cin >> b;
        uint32_t id0 = a - 1;    // 問題では1から、プログラムでは０から始まるので1引いておく。
        uint32_t id1 = b - 1;   // 問題では1から、プログラムでは０から始まるので1引いておく。
        t[id0].next.push_back(&t[id1]);
    }
    
    // 値を加算。
    uint32_t *val = new uint32_t[N];
    //memset(val, 0, sizeof(uint32_t) * N);
    for (uint32_t i = 0; i < Q; i++) {
        uint32_t p, x;
        cin >> p;
        cin >> x;
        uint32_t id = p - 1;
        val[id] += x;
    }
    
    for (int i = 0; i < N; i++) {
        if (val[i] != 0) {
            treeNodeAdd(&t[i], val[i]);
        }
    }
    
    // 出力。
    for (TreeNode tn : t) {
        cout << tn.val << " ";
    }
    
    delete[] val;
    return 0;
}
