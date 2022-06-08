#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;
#define ll long long

int main(){
    int N, K;
    int m = 1;
    int tt=0;
    bool flag = true;
    set<int> s;
    set<int> g;
    cin >> N >> K;
    set<int> D;
    for(int i = 0; i < K; i++){
        cin >> tt;
        if(D.count(tt) == 0){
            D.insert(tt);
        }
        if(m == tt){
            m++;
        }
    }
    for(int i = N; i < 1e9; i++){
        int t = i;
        flag = true;
        while(t > 0){
            int a = t % 10;
            t /= 10;
            if(D.count(a) > 0){
                flag = false;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        } 
    }
}
