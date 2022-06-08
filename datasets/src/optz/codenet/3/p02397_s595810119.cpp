#include <iostream>
#include <queue>
using namespace std;
int main() {
    int a, b, i = 0, j = 0;
    queue <int> q;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        q.push(b);
        q.push(a);
        i++;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        cout << q.front() << ((i != ++j) ? "\n": "");
        q.pop();
    }
}

