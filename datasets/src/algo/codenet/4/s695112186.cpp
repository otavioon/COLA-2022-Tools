#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    set<int> st;
    for(int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    int ans;
    for(int i = n; i <= 99999; i++){
        int mny = i;
        bool ok = true;
        while(mny > 0){
            if(st.count(mny % 10)){
                ok = false;
                break;
            }
            mny /= 10;
        }
        if(ok){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}