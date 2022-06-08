// g++ -std=c++11 test.cpp && ./a.out
// g++ -std=c++11 bfs.cpp && cat bfs.txt | ./a.out

#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

#define PRINT(A) {for (int i = 0; i < A.size(); i++) { cout << A[i] << " ";} cout << endl;}
#define SUM(A) accumulate(A.begin(), A.end(), 0)
#define MAX(A) *max_element(A.begin(), A.end())
#define GETLINE(A) {string I; while(getline( cin, I, ' ' )){A.push_back(stoi(I));}}
#define BIT_LENGTH(N) floor(log2(N)) + 1
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

bool check(double length, int K, VI &logs) {
    int count = 0;
    for (auto log: logs) {
        count += (ceil((double)log / length) - 1);
        if (count > K) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;    
    VI logs;
    GETLINE(logs);

    int left = 1, right = pow(10,9);
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, K, logs)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}