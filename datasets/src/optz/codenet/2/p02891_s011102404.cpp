#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string S;
    long long K; 
    cin >> S;
    cin >> K;

    int count = 0;
    // int count_buff = 0;
    int l = S.length();
    int flag = 0;

    //check start-fin
    // cout << S[0] << S[l-1] << endl;
    for(int i=0; i < l-1; i++){
        if(S[i] == S[i+1] && S[i+1] == S[i+2]){
            count++;
            i++;
        }else if(S[i] == S[i+1]){
            count++;
        }
    }
    
    if(S[0] == S[l-1]){
        count++;
        // cout << '2' << endl;
        if((S[0] == S[l-1] && S[l-1] == S[l-2]) || (S[0] == S[l-1] && S[l-1] == S[1])){
            if((S[0] == S[1] && S[1] == S[2]) || (S[l-1] == S[l-2] && S[l-2] == S[l-3])){
                count++;
            }
            // cout << '1' << endl;
            count--;
        }
    }

    // cout << l << endl;
    cout << count*K << endl;

}