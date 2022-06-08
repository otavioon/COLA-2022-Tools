#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> data(2);
    while(true){
        cin >> data.at(0) >> data.at(1);
        if(data.at(0) == 0 && data.at(1) == 0){
            break;
        }
        else{
            sort(data.begin(),data.end());
            cout << data.at(0) << " " <<data.at(1) << endl;
        }
    }
}

