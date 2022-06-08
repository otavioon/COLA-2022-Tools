#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

// tgt より低い要素数を返す
// (例) tgt = 4, list = [0, 1, 2, 3, 4, 5]ならば、4を返す
int bs_lower(int tgt, vector<int> list){

    int left=0, right=list.size();
    int mid = 0;
    
    while(left<right){
        mid = (left+right)/2;

        if (list[mid]==tgt){

            break;

        }else if(list[mid]<tgt){

            left = mid+1;

        }else if(list[mid]>tgt){

            right = mid;

        }
    }

    return (left+right)/2;

}

// tgtより高い要素数を返す
// (例)tgt = 4, list = [0, 1, 2, 3, 4, 5]ならば、1を返す。
int bs_upper(int tgt, vector<int> list){
    
    int left=0, right=list.size();
    int mid = 0;

    while(left<right){
        mid = (left+right)/2;

        if(list[mid] == tgt){

            break;

        }else if(list[mid]>tgt){

            left = mid+1;

        }else if(list[mid]<tgt){

            right = mid;

        }

    }

    return (left+right)/2;

}

int main(){

    // O(N)
    int N; cin>>N;
    vector<int> A(N), B(N), C(N);
    for (int n=0; n<N; n++) cin>>A[n];
    for (int n=0; n<N; n++) cin>>B[n];
    for (int n=0; n<N; n++) cin>>C[n];

    // O(NlogN)
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    // O(N) * O(logN)
    int ans = 0;
    for (int n=0; n<N; n++){
        
        int A_lower = bs_lower(B[n], A);
        int C_upper = bs_upper(B[n], C);

        ans += A_lower * C_upper;

    }

    cout<<ans<<endl;
    
}