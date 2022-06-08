#include <bits/stdc++.h> 
using namespace std;

int main(){
    int M, N;
    cin >> N;
    string s[N];
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    cin >> M;
    string t[M];
    for(int i=0;i<M;i++){
        cin >> t[i];
    }

    string tmp;
    int x, y;
    x = 1;
    y = 0;
    for(int i=0;i<N;i++){
        tmp = s[i];
        for(int j=i + 1;j<N;j++){
            if(s[j] == tmp) x++;
        }
        for(int k=0;k<M;k++){
            if(t[k] == tmp) x--;
        }
        
        if(y < x) y = x;
        x = 1;
    }
    cout << y << "\n";
}
