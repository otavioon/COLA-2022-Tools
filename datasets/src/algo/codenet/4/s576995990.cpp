#include<iostream>
#include<set>
using namespace std;

int n, k;
set<int> D;

bool check(int x){
    while(x > 0){
        if(D.find(x%10) != D.end()) return false;
        x /= 10;
    }

    return true;
}

int main(){

    cin >> n >> k;

    int d;
    for(int i = 0; i < k; i++){
        cin >> d;
        D.insert(d);
    }

    while(!check(n)){
        n++;
    }

    cout << n << endl;
    return 0;
}