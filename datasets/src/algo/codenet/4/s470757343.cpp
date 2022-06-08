#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   //0-origin昇順
#define rep1(i,n) for(int i = 1; i <= ((int)(n)); i++) //1-origin昇順
#define rrep(i,n) for(int i = ((int)(n)-1); i >= 0; i--)  //0-origin降順
#define rrep1(i,n) for(int i = ((int)(n)); i >= 1; i--)   //1-origin降順
//rep2 -> 第二引数 m から n 回繰り返し ex) m=5 n=3 なら i=5,i=6,i=7 まで
#define rep2(i,m,n) for(int i = ((int)(m)); i < ((int)(n))+((int)(m)); i++)
#define SIZE(x) ((int)((x).size()))
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vii; //2次元配列
typedef vector<ll> vll;
typedef vector<string> vs;
template<typename T> bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1;} return 0;}
template<typename T> bool chmin(T &a, const T &b){ if(a>b){ a=b; return 1;} return 0;}


/*FUNCs=================================================*/


/*MAIN==================================================*/
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化

    int n, k; cin >> n >> k;
    set<char> no;
    rep(i,k){
        char qwertyuiop; cin >> qwertyuiop;
        no.insert(qwertyuiop);
    }
    bool can = true;
    string answer;
    n--;
    while(can){
        n++;
        string str = to_string(n);
        for(char ch : str){
            can = false;
            if(no.find(ch) != no.end()){
                can = true;
                break;
            }
            if(!can) answer = str; 
        }
    }
    cout << answer << '\n'; 
}