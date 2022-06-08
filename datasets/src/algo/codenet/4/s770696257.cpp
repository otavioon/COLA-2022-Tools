#include<bits/stdc++.h>

using namespace std;

int main(){
    int k, arr[11] = {0}, truer = 0;
    set<int> se;
    string s;
    cin >> s >> k;
    for(int i = 0; i < k; ++i){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    for(int i = 0; i < se.size(); ++i){
        if(se.find(i) != se.end()){

        }else arr[i] = true;
    }
    for(int i = 0; i < s.length(); ++i){
        if(se.find(s[i] - '0') != se.end()){
            for(int j = 0; j < 11; ++j){
                if(arr[j] == 1 && (s[i] - '0') < j){
                    s[i] = j + '0';
                    truer = true;
                    break;
                }
            }
        }
        if(truer){
            int min;
            for(int j = 0; j < 11; ++j){
                if(arr[j]){min = j; break;}
            }
            for(int j = i + 1; j < s.length(); ++j){
                s[j] = min + '0';
            }
            cout << s;
            return 0;
        }
    }
    cout << s;
    return 0;
}
