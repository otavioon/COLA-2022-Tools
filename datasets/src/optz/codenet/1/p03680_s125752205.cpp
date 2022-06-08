#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
    int N;
    cin >> N;
    int a[N];
    REP(i,N){
        cin >> a[i];
    }
    int cnt=0;
    int x=0;
    bool flag = false;
    REP(i,N){
        x = a[x-1];
        cnt += 1;
        if(x==2){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << cnt;
    }else{
        cout << -1;
    }

}