#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

int vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
    if (index != vec.size()) { // 発見できたとき
        return 1;
    }
    else { // 発見できなかったとき
        return 0;
    }
}

int main() {
    string n; int k; cin >> n >> k;
    vector<int> d(k);
    rep(i, k) cin >> d[i];
    sort(d.begin(), d.end());
    vector<int> dd{0,1,2,3,4,5,6,7,9};

    vector<int> allowed_num;
    set_difference(dd.begin(), dd.end(), d.begin(), d.end(), back_inserter(allowed_num));


    string ans = n;
    bool up_flag2 = false;
    while(true) {
        bool flag = true;
        rep(i, ans.size()) {
            if(!vector_finder(allowed_num, ans[i]-'0')) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << ans << endl;
            return 0;
        } else {
            // 桁をあげる
            bool up_flag = true;
            rep(i, ans.size()) {
                if(!(ans[i]-'0' == allowed_num[allowed_num.size()-1])) {
                    up_flag = false;
                    break;
                }
            }
            if(up_flag || up_flag2) {
                int tmp = ans.size();
                ans = "";
                rep(i, tmp+1) {
                    if(i == 0 && allowed_num[0] == 0) {
                        ans += to_string(allowed_num[1]);
                    } else {
                        ans += to_string(allowed_num[0]);
                    }
                }
                up_flag=false;
                up_flag2=false;
                continue;
            }

            // NGの箇所を1つあげる
           for(int i=ans.size()-1; i >= 0; i--) {
                if(!vector_finder(allowed_num, ans[i]-'0')) {
                    auto idx = lower_bound(allowed_num.begin(), allowed_num.end(), ans[i]-'0');
                    int index = idx - allowed_num.begin();
                    if(index == allowed_num.size()) {
                        if(i == 0) up_flag2 = true;
                        break;
                    }
                    ans.replace(i, 1, to_string(allowed_num[index]));
                    for(int j=i+1; j < ans.size(); j++) {
                        ans.replace(j, 1, to_string(allowed_num[0]));
                    }
                    break;
                }
            }
        }
    }

}

