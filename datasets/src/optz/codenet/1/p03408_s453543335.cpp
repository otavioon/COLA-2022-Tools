#include <iostream>
#include <string>
using namespace std;
int main(){
    int N, M;
    cin >> N;
    char s[N][100];
    int S[100] = {0};
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    cin >> M;
    char t[M][100];
    for(int j = 0; j < M; j++){
        cin >> t[j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
                if(s[i] == s[j])
                    S[i] = S[i] + 1;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(s[i] == t[j])
                S[i] = S[i] - 1;
        }
    }
    int tmp = 0;
    for(int i = 0; i < 100; i++){
        if(i == 0)
            tmp = S[i];
        if(S[i] > tmp)
            tmp = S[i];
        }
    cout << tmp << endl;
    return 0;
}
