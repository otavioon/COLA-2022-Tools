#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
using ll=long long;
 
 
string inp;
string o;
int re;
ll ans1=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>inp>>re;
    o=inp;
    inp=inp+inp;

    bool same=1;
    for(int i=1;i<inp.size();i++){
        if(inp[i]!=inp[i-1]){
            same=0;
        }
    }

    if(same){
        //cout<<(ll)o.size()*re/2<<endl;
        //return 0;
    }
 
    ll need=0,last=0;
    for(int i=1;i<inp.size();i++){
        if(inp[i]==inp[i-1]){
            inp[i]='#';
            need++;
            if(i>=o.size())last++;
        }
    }
    ans1=need-last+last*(re-1);
 
 
    return 0;
}