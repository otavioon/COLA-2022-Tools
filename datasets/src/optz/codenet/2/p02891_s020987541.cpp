#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string S; cin >> S;
    long long K; cin >> K;
    vector<int> l;
    auto prev = S[0];
    int cnt = 0;
    for(auto& c : S){
        if(c == prev) ++cnt;
        else {
            l.push_back(cnt);
            prev = c;
            cnt = 1;
        }
    }
    l.push_back(cnt);
    if(S[0] == S.back()){
        if(l.size() == 1) cout << l[0] * K / 2 << endl;
        else {
            long long res = l[0]/2 + (l[0]+l.back())/2*(K-1) + l.back()/2;
            for(int i=1;i<l.size()-1;i++) res += l[i]/2 * K;
            cout << res << endl;
        }
    } else {
        long long res = 0;
        for(auto& t : l) res += t/2 * K;
        cout << res << endl;
    }
}