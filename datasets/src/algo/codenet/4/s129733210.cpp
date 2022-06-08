#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,K;
    cin >> N >> K;
    vector<bool> hate(10);
    for(int i = 0;i < K;i++) {
        int A;
        cin >> A;
        hate.at(A) = true;
    }
    for(int i = N;i < 1000000000;i++) {
        int cnt = i;
        bool cnt2 = true;
        while(cnt > 0) {
            if(hate.at(cnt % 10) == true) {
                cnt2 = false;
                break;
            }
            cnt /= 10;
        }
        if(cnt2 == true) {
            cout << i << endl;
            break;
        }
    }
}