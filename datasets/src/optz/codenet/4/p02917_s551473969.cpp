#include <iostream>

#define n 100

using namespace std;

int N;
int B[n-1] = {};

int ans=0;

int main(){
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        cin >> B[i];
    }

    ans += B[0];
    ans += B[N - 2];
    for (int i = 1; i < N - 1; i++){
        ans += min(B[i], B[i - 1]);
    }

    cout << ans;

    return 0;
}