#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,k[110]={0};
    string s[110],t[110];
    cin >> N;
    for(int i=0;  i<N; i++){
        cin >> s[i];
    }
    cin >> M;
    for(int i=0;  i<M; i++){
        cin >> t[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(s[i] == s[j]){
                k[i]++;
            }
        }

        for(int j=0; j<M; j++){
            if(s[i] == t[j]){
                k[i]--;
            }
        }
    }
    sort(k,k+110);
    reverse(k,k+110);
    if(k[0] > 0){
        cout << k[0] << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
