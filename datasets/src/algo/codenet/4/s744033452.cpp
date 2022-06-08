#include <iostream>
#include <set>

using namespace std;

set<int> st;

bool is_n_ok(int n) {
    bool flag=true;
    while(n!=0) {
        if(st.count(n%10)) {
            flag = false;
            break;
        }
        n /= 10;
    }
    return flag;
}

int main() {
    int N, K;
    cin >> N >> K;
    for(int k=0; k<K; k++) {
        int d;
        cin >> d;
        st.insert(d);
    }
    
    while(!is_n_ok(N)) {
        N++;
    }
    
    cout << N << endl;

    return 0;
    
}