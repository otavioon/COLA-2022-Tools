#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
        if(A==1 && B==1){
            cout << "Draw";
        }
        else if(A==1 && B>=2 && B<=13){
            cout << "Alice";
        }
        else if(B==1 && A>=2 && A<=13){
            cout << "Bob";
        }
        else if(A>B){
            cout << "Alice";
        }
        else if(B>A){
            cout << "Bob";
        }
    return 0;
}