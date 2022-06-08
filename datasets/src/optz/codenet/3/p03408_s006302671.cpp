#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N,M;
    int counter,counter_max = 0;

    cin >> N;
    vector<string> str_s(N);

    for(int i = 0;i < N;i++){
        cin >> str_s[i];
    }

    cin >> M;
    vector<string> str_t(M);

    for(int i = 0;i < M;i++){
        cin >> str_t[i];
    }

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(str_s[i] == str_s[j])counter++;
        }
        for(int k = 0;k < M;k++){
           if(str_s[i] == str_t[k])counter--;
        }
        counter_max = max(counter,counter_max);
        counter = 0;
    }

    cout << counter_max << endl;
}