#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, K, M, T;

int main() {
    cin >> N >> K;
    string s = to_string(N);
    set<int> st;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        st.insert(d);
    }
    int m = N;
    while (1) {
        string t = to_string(m);
        bool flag = true;
        for (char c : t) {
            if (st.find(c - '0') != st.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            break;
        } else {
            m++;
        }
    }
    cout << m << endl;
    
    return 0;
}