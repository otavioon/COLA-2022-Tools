#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a;
    a.push_back(1);
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    int count = 0;
    int now = 1;
    for(;;){
        now = a[now];
        count++;
        if(now == 2){
            cout << count << endl;
            break;
        }
        if (count >= N){
            cout << "-1" << endl;
            break;
        }
    }
    return 0;
}