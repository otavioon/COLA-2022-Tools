#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long unsigned int ll;

int calc_sad(vector<int> A, int b) {
    int sad = 0;
    rep(i, A.size()) {
        sad += abs(A[i] -b);
    }
    return sad;
}

int main() {
    int N;
    vector<int> A;
    cin >> N;
    rep(i, N) {
        int a;
        cin >> a;
        a -= i;
        A.push_back(a);
    }

    vector<int> B;
    copy(A.begin(), A.end(), back_inserter(B) );
    sort(B.begin(), B.end());
    int b = B[B.size()/2];

    int result = calc_sad(A, b);

    cout << result << endl;
    return 0;
}