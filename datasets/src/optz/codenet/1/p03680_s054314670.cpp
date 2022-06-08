#include <bits/stdc++.h>
using namespace std;

int main() {
    int j=1, k=0, count=1;
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a.at(i);
    vector<int> b(1000000);
    
    b.at(0) = a.at(0);
    while(1){
        b.at(j) = a.at(b.at(k)-1);
        if(b.at(j-1) == 2){
            cout << count << endl;
            break;
        }
        else{
            if(j >= 2){
                if(b.at(j) == b.at(j-2)){
                    cout << "-1" << endl;
                    break;
                }
            }
        }
        count++;
        j++;
        k++;
    }
}