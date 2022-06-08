#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    vector<set<int>> tree(n);
    for (int i=0; i<n-1;i++){
        int a,b;
        cin >> a >> b;
        tree.at(a-1).insert(b-1);
    }

    vector<int> sousa(n);
    for (int i=0; i<q;i++){
        int p,x;
        cin >> p >> x;
        sousa.at(p-1) += x;
    }

    vector<int> point(n);
    queue<int> nodes;
    nodes.push(0);
    //for(int count = 0 ; count < 10; count++){
    while(!nodes.empty()){
        int node = nodes.front();
        point.at(node) += sousa.at(node);
        cout << node << endl;    
        for(auto itr = tree.at(node).begin(); itr != tree.at(node).end(); ++itr) {
            int child = *itr;
                    cout << "child" << child << endl;  
            point.at(child) += point.at(node);
            nodes.push(child);
        }
        nodes.pop();
        cout << "size" << nodes.size() << endl;
    }

    for (int i=0; i<n;i++){
        cout << point.at(i) << " ";
    }

}