
#include <bits/stdc++.h>

using namespace std;
 
 
int main() {

    int n;
    cin>>n;
    vector<int>A;

    int j = 0;
    for (int i = 0; i < n-1; i++) {
        cin>>j;
        A.push_back(j);
    }


    int sum = 0;
    int size = A.size();
    for (int i = 0; i < size; i++) {
        //first
        if(i==0){
            sum+=A[i];

            //last
        }else if(i== size-1){
            sum+=A[size-1];

            //others
        }else{
            if(A[i] < A[i-1]){
                sum+=A[i];
            }else{
                sum+=A[i+1];
            }
        }
    }

    cout<<sum;

    return 0;

}
