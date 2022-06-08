#include<bits/stdc++.h>
using namespace std;

int vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
    if (index != vec.size()) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    string N;
    int K;
    int zflag = 0;
    int min = 100;
    int flag = 0;
    cin >> N >> K;
    vector<int> d(K);
    for(int i = 0;i < K; i++){
        cin >> d[i];
        if(d[i] != i && flag != 1){
            int min = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < N.size(); i++){
        ans = N[i] - '0';
        if(i == 0){
            for(int j = 0; j < 10; j++){
                if(ans == 10){
                    zflag = 1;
                    flag = 1;
                    ans = 0;
                }
                if(vector_finder(d,ans) != 1){
                    cout << ans;
                    break;
                }
                ans++;
            }
            if(zflag == 1){
                cout << min;
            }
        }else{
            if(flag == 0){
                cout << ans;
            }else{
                cout << min;
            }
        }
    }
    cout << endl;
    return 0;
}