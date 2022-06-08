#include <iostream>
#include <queue>
using namespace std;
int main() {
    int a, b;
    queue <int> q;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        q.push(b);
        q.push(a);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        cout << q.front() << "\n";
        q.pop();
    }
}

