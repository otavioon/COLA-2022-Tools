#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;



int n,k;
set<int> D;

bool judge(int x){
    while(x>0){
        if(D.find(x%10) !=D.end()){
            return false;
        }
        x/=10;
    }
    return true;
}




int main(){
    cin >> n >> k;
    int tmp;
    REP(i,k){
        cin >> tmp;
        D.insert(tmp);
    };
    int ans = n;
    while(1){
        if( judge(ans)){
            cout << ans << endl;
            return 0;
        }
        ans+=1;
    }
}