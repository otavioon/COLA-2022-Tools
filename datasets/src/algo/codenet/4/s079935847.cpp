#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    set<int> D;
    int d;
    for (int i = 0; i < K; i++) {
        cin >> d;
        D.insert(d);
    }
    int num = N;
    string numS;
    bool correct = false;
    while (correct == false) {
        correct = true;
        stringstream ss;
        ss << num;
        ss >> numS;
        for (int i = 0; i < numS.length(); i++) {
            if (D.count(numS[i]-'0') == 1) {
                correct = false;
            }
        }
        if (correct == false) {
            num += 1;
        }
    }
    cout << num;

    return 0;
}
