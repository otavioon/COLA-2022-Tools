#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    set<char> D;
    for(int i = 0; i < K; ++i) {
        char c;
        cin >> c;
        D.insert(c);
    }

    for(;; ++N) {
        string S = to_string(N);
        bool valid = true;
        for(char c: S) {
            if(D.count(c) > 0) {
                valid = false;
            }
        }
        if(valid)
            break;
    }

    cout << N << endl;

    return 0;
}
