#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>

using namespace std;


int main(){
    int N;
    cin >> N;
    int A[N],B[N],C[N];
    for(int i = 0; i < N; i ++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i ++){
        cin >> B[i];
    }
    for(int i = 0; i < N; i ++){
        cin >> C[i];
    }

    sort(A, A+N);
    sort(B, B+N);
    sort(C, C+N);

    int count = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i]>=B[j]){
                continue;
            }else{
                for(int k = 0; k < N; k++){
                    if(B[j] >= C[k]){
                        continue;
                    }else{
                        //printf("%d,%d,%d\n",A[i],B[j],C[k]);
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
