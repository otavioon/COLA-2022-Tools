#include<bits/stdc++.h>
using namespace std;
#define ll long long

void CountTriangles(vector <int> A){

    int n=A.size();

    sort(A.begin(), A.end());

    ll cnt = 0;

    for( int i = n-1; i >= 1; i--){
        int l = 0, r = i-1;
        while( l < r){
            if( A[l] + A[r] > A[i]){

                // If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1],a[r] and a[i]
                cnt += r - l ;

                //checking for more possible solutions
                r--;
            }
            else

                // if not possible check for
                // higher values of arr[l]
                l++;
        }
    }
    printf("%lld\n",cnt);

    //cout<<"No of possible solutions: "<<count;
}
int main(){
    int n;
    scanf("%d",&n);



    vector<int> A ;

    for(int i=0;i<n;i++)
    {
        int v;
        scanf("%d",&v);
        A.push_back(v);
    }

    CountTriangles(A);

}
