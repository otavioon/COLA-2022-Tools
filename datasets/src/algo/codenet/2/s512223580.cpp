#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    multiset<int> st;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    while(st.size()){
        auto it = prev(st.end());
        int a = *it;
        st.erase(it);
        int pw = 1;
        while(pw-a <= 0) pw *= 2;
        int b = pw-a;
        auto it2 = st.find(b);
        if(it2 != st.end()){
            ans++;
            st.erase(it2);
        }
    }
    cout << ans << endl;
}