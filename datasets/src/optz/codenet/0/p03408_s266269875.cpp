#include<iostream>
using namespace std;
int main(){
  int N, M;
  cin >> N;
  string blue[N];
  for (int i = 0; i < N;i++){
    cin >> blue[i];
  }
  
  cin >> M;
  string red[M];
  for (int i = 0; i < M;i++){
    cin >> red[i];
  }
  
  int cnt_2 = 0;
 
  for (int i = 0; i < N; i++)
  { int cnt = 1;
    string tmp = blue[i];
    for (int j = i + 1; j < N;j++){
      if(blue[j]==tmp){
        cnt++;
        //cout << "+tmp "<<blue[j] << endl;
      }
    }
    
    for (int j = 0; j < M;j++){
      if(red[j]==tmp){
        cnt--;
        //cout << "-tmp " << red[j];
      }
        if(cnt==0)
          break;
      
    }
    if(cnt_2<cnt){
      cnt_2 = cnt;
    }
  }
   cout << cnt_2 << endl;
}
