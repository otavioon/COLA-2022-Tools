#include <bits/stdc++.h>
using namespace std;

int n,k;
set<int> d;

inline bool check(int pay){

    vector<int> digits;

    while(pay != 0){
        digits.push_back(pay%10);
        pay /= 10;
    }

    for(auto i : digits){
        if(d.find(i) != d.end()){
            return false;
        }
    }

    return true;

}


int main() {

    cin >> n >> k;

    for(int i=0; i<k; i++){
        int input;
        cin >> input;
        d.insert(input);
    }


    while(!check(n)){
        n++;
    }

    cout << n << endl;

    return 0;
}