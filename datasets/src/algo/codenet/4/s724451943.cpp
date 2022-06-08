#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string N; int K,t; cin >> N >> K;
    set<int> a;
    for(int i=0;i<K;i++){
        cin >> t;
        a.insert(t);
    }
    string ans = "";
    int car = N.size();
    bool c = 0;
    for(int i=N.size()-1;i>=0;i--){
        for(int j=N[i]-'0'+c;j<30;j++){
            if(!a.count(j%10)){
                if('0'+j%10 < N[i]){
                    car = i-1;
                    c = 1;
                }
                else{
                    c = 0;
                }
                break;
            }
        }
    }
    for(int i=0;i<car;i++){
        for(int j=N[i]-'0';j<30;j++){
            if(!a.count(j%10)){
                ans += '0'+j%10;
                break;
            }
        }
    }
    if(0<= car && car <N.size()){
        for(int j=(N[car]-'0')+1;j<30;j++){
            if(!a.count(j%10)){
                ans += '0'+j%10;
                break;
            }
        }
    }
    else if(car == -1){
        for(int j=1;j<30;j++){
            if(!a.count(j%10)){
                ans += '0'+j%10;
                break;
            }
        }
    }

    for(int i=car+1;i<N.size();i++){
        for(int j=0;j<10;j++){
            if(!a.count(j)){
                ans += '0'+j;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
