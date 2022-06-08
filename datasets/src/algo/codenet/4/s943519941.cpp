#include<iostream>
#include<set>

using namespace std;

int main(){
    int K, N, i=0;
    int input, output;
    cin >> N >> K;
    
    set<int> num;

    while (i < K){
        cin >> input;
        num.insert(input);
        i++;
    }

    int a1, a2, a3, a4, a5;
    output = N;
    while (1){
        a5 = output / 10000;
        a4 = (output % 10000) / 1000;
        a3 = (output % 1000) / 100;
        a2 = (output % 100) / 10;
        a1 = (output % 10);
        if (num.find(a5) == num.end() && num.find(a4) == num.end() && num.find(a3) == num.end() && num.find(a2) == num.end() && num.find(a1) == num.end()){
            break;            
        }
        output += 1;
    }
    
    cout << output << endl;
    return 0;
}