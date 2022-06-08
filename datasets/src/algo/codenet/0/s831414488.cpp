#include<iostream>
using namespace std;

int main(){
    bool plus = false, ilast = false;
    string S;
    long long K;
    int cnt = 0;

    cin >> S >> K;

    for(int i=0; i<S.length(); i++){
        if(i == S.length() - 1){
            ilast = true;
        } else if(S[i] == S[i+1]){
            cnt++;
            i++;
        }
    }
    if(ilast){
        if(S[S.length() - 1] == S[0]) plus = true;
    }

    if(plus){
        cout << cnt*K + K - 1;
    } else{
        cout << cnt*K;
    }
}