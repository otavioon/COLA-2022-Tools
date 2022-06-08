#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;

void readline(int N, vector<int> &a){
    string s;
    for(int i = 0; i < N - 1; i++){
        getline(cin, s, ' ');
        a[i] = atoi(s.c_str());
    }
    getline(cin, s, '\n');
    a[N - 1] = atoi(s.c_str());
}
void readline(int N, vector<double> &a){
    string s;
    for(int i = 0; i < N - 1; i++){
        getline(cin, s, ' ');
        a[i] = atof(s.c_str());
    }
    getline(cin, s, '\n');
    a[N - 1] = atof(s.c_str());
}

int main(){

    int N;
    cin >> N;
    
    vector<int> A(N);

    readline(N, A);

    sort(A.begin(), A.end());

    cout << A[N - 1] - A[0];

    return 0;
    
}