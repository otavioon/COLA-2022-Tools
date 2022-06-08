#include <bits/stdc++.h>
using namespace std;

int main() {
  int N_yen, K_num;
  cin >> N_yen >> K_num;
  int Disfig[K_num];
  for(int i = 0; i < K_num; i++){
    cin >> Disfig[i];
  }
  for(int ans = N_yen; ans < 100000; ans++){
    set<int> digit_fig;
    int keep_yen = ans;
    //各桁の数を配列に入れる
  	while(keep_yen != 0){
    	digit_fig.insert(keep_yen%10);
    	keep_yen /= 10;
  	}
    bool judge = true;
  	for(int j = 0; j < K_num; j++){
    	if(digit_fig.count(Disfig[j])){
          judge = false;
        }
  	}
  	if(judge == true){
    	cout << ans << endl;
      	break;
  	}
  }
  return 0;
}