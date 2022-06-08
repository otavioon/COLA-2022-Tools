#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    int k;
    cin >> n >> k;
    set<int> d;
    for(int i=0; i<k; i++){
        int a;
        cin >> a;
        d.insert(a);
    }
    while(1){
        string s;
        s = to_string(n);
        bool ok=true;
        for(int i=0; i<s.size(); i++){
            if(d.count(s.at(i)-'0')) ok=false;
        }
        if(ok){
            cout << n << endl;
            return 0;
        }
        n++;
    }
}