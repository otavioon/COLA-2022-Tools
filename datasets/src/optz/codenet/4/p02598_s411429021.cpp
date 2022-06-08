#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    int max = 0;
    int min = 1;
    int count;

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(max < A.at(i)){
            max = A.at(i);
        }
    }

    int answer = (max + min) / 2;

    while(1){

        count = 0;
        for(int i = 0; i < N; i++){ // すべての丸太の長さをanswer以下にするために必要な切断回数を求める
            if(A.at(i) % answer == 0){
                count += (A.at(i) / answer) - 1;
            }else{
                count += (A.at(i) / answer);
            }
        }

        if(count <= K){ // 条件を満たしており、もっと短いところを探索
            max = answer;
            answer = (min + max) / 2;
            if(max == min){
                break;
            }
        }else{ // 条件を満たしておらず、もっと長いところを探索
            min = answer + 1;
            answer = (max + min) / 2;
            if(max == min){
                break;
            }
        }

    }

    cout << answer << endl;

}