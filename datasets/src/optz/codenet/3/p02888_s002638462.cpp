#include <bits/stdc++.h>
using namespace std;
int main(void){

    int input, ans = 0, flag;
    cin >> input ;
    
    vector<int> side(input);
    for(int i = 0; i < input; i++){
        cin >> side.at(i);
    }
    
    sort(side.begin(), side.end());
    reverse(side.begin(), side.end());

    for(int i = 0; i < input; i++){
        flag = 0;
        for(int j = i + 1; j < input; j++){
            for(int k = j + 1; k < input; k++){
                if(side.at(i) < side.at(j) + side.at(k) && side.at(j) < side.at(k) + side.at(i) && side.at(k) < side.at(i) + side.at(j) ){
                    ans++;
                } else {
                    break;
                    flag++;
                }
            }
            if(flag != 0){
                break;
            }
        }
    }

    cout << ans << endl;

}
