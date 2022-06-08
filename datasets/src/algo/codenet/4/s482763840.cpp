#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, K;
    cin >> N >> K;
    set<int> A;
    int tmp;
    for (int i = 0; i < K; i++) {
        cin >> tmp;
        A.insert(tmp);
    }
    bool check;
    int t;
    for (int i = N; i < 1000005; i++) {
        tmp = i;
        check = true;
        while(tmp > 0){
            t = tmp % 10;
            if(A.count(t)){
                check = false;
            }
            tmp = tmp / 10;
        }
        if(check){
            printf("%d\n", i);
            return 0;
        }
    }

}