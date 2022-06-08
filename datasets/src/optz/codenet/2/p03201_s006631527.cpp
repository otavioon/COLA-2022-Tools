#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

ll getMinBi(ll x){
    int i = 2;
    while(true){
        if(i < x && x < i * 2){
             return i;
        }else{
            i *= 2;
        }
    }
}

int main() {
    ll N;
    cin >> N;
    vector<int> A(N);
    ll count = 0;
    bool used[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
        used[i] = false;
    }
    sort(A.begin(),A.end());
    for (int i = 0; i < N; ++i) {
        ll currentX = A[N - i -1];
        if(used[N - i - 1] || currentX <= 2){
            continue;
        }
        ll Y = getMinBi(currentX) * 2;
        auto it = lower_bound(A.begin(), A.end(), Y - currentX);
        if(*it == Y-currentX){
            int index = it - A.begin();
            used[index] = true;
            used[N - i - 1] = true;
            count++;
        }
    }
    cout << count << endl;

}
