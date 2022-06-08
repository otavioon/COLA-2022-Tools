#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> P;
typedef pair<ll, ll> PL;
const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}
 
ll n;
ll a[200001];
char mem[1000000001];
int num[200001];
ll mem_two[30];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(mem[a[i]] == '1') num[i]++;
        mem[a[i]] = '1';
    }

    int cou = 1;
    int ind = 0;
    ll ma = 1000000000;
    while(cou<<1 < ma){
        cou <<= 1;
        mem_two[ind] = cou;
        ++ind;
    }

    ll ans = 0;
    ll temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < ind; j++){
            temp = mem_two[j] - a[i];
            if(temp < 2)    continue;
            if(temp == a[i] && num[i] < 1)  continue;
            if(mem[temp] == '1'){
                ++ans;
               // cout << temp << ' ' << a[i] << endl;
                mem[temp] = '0';
                mem[a[i]] = '0';
                break;
            }
        }
    }
    cout << ans << endl;
}