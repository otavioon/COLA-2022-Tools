#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ALL(a) (a).begin(),(a).end()
template<typename T>
ostream& operator <<(ostream &s, const vector<T> A){
    for(int i=0, n=A.size(); i<n; i++){
        if(i) s << " ";
        s << A[i];
    }
    return s;
}

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin>>A[i];
    sort(ALL(A));
    long long cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            auto a = upper_bound(ALL(A), A[j]);
            auto b = --lower_bound(ALL(A), A[i]+A[j]);
            if(b>=a) cnt += b-a+1;
        }
    }
    cout << cnt << endl;
}

