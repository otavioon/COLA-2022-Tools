#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    vector<Node*> children;
    int point;
public:
    Node(){
        point = 0;
    }
    void AddPoint(int x){
        point += x;
        for(auto child : children){
            child->AddPoint(x);
        }
    }
    void AddChild(Node* child){
        children.push_back(child);
    }
    int Point(){
        return point;
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    Node** nodes = new Node*[N];
    for(int i = 0; i < N;i++){
        nodes[i] = new Node();
    }
    for (int i = 0; i < N-1;i++){
        int a, b;
        cin >> a >> b;
        nodes[a-1]->AddChild(nodes[b-1]);
    }
    for (int i = 0; i < Q;i++){
        int p, x;
        cin >> p >> x;
        nodes[p-1]->AddPoint(x);
    }
    for (int n = 0; n < N;n++){
        cout << nodes[n]->Point() << (n == N -1 ? "\n" : " ");
    }
}