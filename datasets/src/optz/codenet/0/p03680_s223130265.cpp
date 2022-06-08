//065
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n; i++)

using namespace std;
int main(void){
    int n, now, cnt=1;
    cin >> n;
    vector<int>L(n,0);
    vector<int>visit{1};
    rep(i,n) cin >> L[i];
    now = 0;
    while(true){
        if(L[now]==2){
            cout << cnt << endl;
            return 0;
        }
        now = L[now]-1;
        cnt +=1;
        auto itr = find(visit.begin(), visit.end(), L[now]); //vector find
        if (itr !=visit.end()){ //ある場合 ない場合 itr==L.end()
            cout << -1 << endl;
            return 0;
        }else{
            visit.push_back(L[now]);
        }
    }
}