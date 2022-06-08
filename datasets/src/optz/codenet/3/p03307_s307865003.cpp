#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;


int main(){

    int N;
    string s;
    getline(cin, s);
    N = atoi(s.c_str());

    vector<int> A(N);

    int i = 0;
    while(getline(cin, s, ' ')){
        A[i] = atoi(s.c_str());
        i++;
    }

    sort(A.begin(), A.end());

    cout << A[N - 1] - A[0];

    return 0;
    
}