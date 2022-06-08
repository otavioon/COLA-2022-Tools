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

    int a1, a2, a3, a4;
    output = N;
    while (1){
        a4 = output / 1000;
        a3 = (output - a4 * 1000) / 100;
        a2 = (output - a4 * 1000 - a3 * 100) / 10;
        a1 = (output - a4 * 1000 - a3 * 100 - a2 * 10);
        cout << a4 << a3 << a2 << a1 << endl;
        if (num.find(a4) == num.end() && num.find(a3) == num.end() && num.find(a2) == num.end() && num.find(a1) == num.end()){
            break;            
        }
        output += 1;
    }
    
    cout << output << endl;
    return 0;
}