#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;

    cin >> N;
    vector<string> blues(N);
    for(int i=0; i<N; i++) {
        cin >> blues[i];
    }

    cin >> M;
    vector<string> reds(M);
    for(int i=0; i<M; i++) {
        cin >> reds[i];
    }

    set<string> card_types;
    for(int i=0; i<N; i++) {
        card_types.insert(blues[i]);
    }
    for(int i=0; i<M; i++) {
        card_types.insert(reds[i]);
    }

    int max = -1000;
    int sum;
    for(string select_card : card_types) {
        sum = 0;
        for(int i=0; i<N; i++) {
            if(blues[i] == select_card) {
                sum += 1;
            }
        }
        for(int i=0; i<M; i++) {
            if (reds[i] == select_card) {
                sum -= 1;
            }
        }

        if (sum > max) {
            max = sum;
        }
    }

    if (max < 0) {
        max = 0;
    }

    cout << max << endl;
    return 0;
}