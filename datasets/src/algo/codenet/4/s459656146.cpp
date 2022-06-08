#include<iostream>
#include<set>

using namespace std;

int main(){
    int K, N;
    int input;
    cin >> N >> K;
    
    set<int> set;

    for (int i=0; i < K; i++){
        cin >> input;
        set.insert(input);
    }

    while (1){
        if (set.find(N%10)!=set.end()){
            N++;
            continue;
        }
        if (set.find(N%100/10)!=set.end() && N>=10){
            N++;
            continue;
        }
        if (set.find(N%1000/100)!=set.end() && N>=100){
            N++;
            continue;
        }
        if (set.find(N%10000/1000)!=set.end() && N>=1000){
            N++;
            continue;
        }
        if (set.find(N%100000/10000)!=set.end() && N>=10000){
            N++;
            continue;
        }
        break;
    }
    cout << N << endl;
    return 0;
}