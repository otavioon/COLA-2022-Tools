#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N ;
    
    vector<int> a(N);
    
    for (int i=0; i<N; i++) {
        cin >> a.at(i);
    }
    
    int count=0;
    
    int p=1;
    

    for (int i=0; i<N; i++) {
        if( p != 2 ){
            count++;
            p=a.at(p-1);
        }
        else{
            cout <<endl << count <<endl;
            break;
        }
    }
    
    if( p != 2){
        cout <<endl << -1 <<endl;
    }
}

