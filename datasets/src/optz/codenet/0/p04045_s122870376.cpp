#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) long long((x).size())
#define OUT(x) cout << (x) << endl
typedef long long ll;
typedef vector<ll> V;
typedef vector<vector<ll>> VV;
typedef pair<ll, ll> P;
typedef map<string, ll> M;
typedef unordered_map<ll, ll> HM;
typedef set<ll> S;
typedef multiset<ll> MS;
typedef queue<ll> Q;

int main(){
    int n,k; cin>>n>>k;
    vector<int> d(k);
    for(int i=0; i<k; i++)
        cin >> d[i];
    while(1){
        int tmp = n;
        bool flag = true;
        while(tmp){
            auto itr = find(ALL(d),tmp%10);
            if(itr != d.end()){
                flag = false;
                break;
            }
            tmp /= 10;
        }
        if(flag)
            break;
        n++;
    }
    OUT(n);
}
