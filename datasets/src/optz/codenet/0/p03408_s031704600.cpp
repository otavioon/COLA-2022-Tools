#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;  cin >> N;
    vector<string> S;
    vector<int> scount;

    string s;
    cin >> s;
    S.push_back(s);
    scount.push_back(1);


    for(int i = 0;i < N - 1;i++){
      cin >> s;
      if(find(S.begin(),S.end(),s) == S.end()){//入力した文字列がSに入っていないとき
        S.push_back(s);//文字列の追加.
        scount.push_back(1);
      }
      else{
        scount[find(S.begin(),S.end(),s)-S.begin()]++;//カウントを+1する.
      }
    }

    vector<string> T;
    vector<int> tcount;

    cin >> M;

    string t;
    cin >> t;
    T.push_back(t);
    tcount.push_back(1);
    for(int j = 0;j < M-1;j++){
      cin >> t;
      if(find(T.begin(),T.end(),t) == T.end()){//入力した文字列がTに入っていないとき
        T.push_back(t);
        tcount.push_back(1);
      }
      else{
        tcount[find(T.begin(),T.end(),t) - T.begin()]++;//カウントを+1する.
      }
    }

    int max = -10000;
    int l;
    for(int i = 0;i < S.size();i++){
      if(find(T.begin(),T.end(),S[i]) != T.end()){//S[i]がTに含まれるとき
          l = scount[i] - tcount[find(T.begin(),T.end(),S[i]) - T.begin()];//差額
          if(max < l)max = l;
      }
      else{
        if(scount[i] > max)max = scount[i];
      }
    }

    if(max < 0)cout << 0 << endl;
    else cout << max << endl;


}