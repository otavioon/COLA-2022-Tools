#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int N;cin>>N;
    int A[100010],B[100010],C[100010];
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++)cin>>B[i];
    for(int i=0;i<N;i++)cin>>C[i];
    sort(A,A+N);sort(B,B+N);sort(C,C+N);
    ll ans=0;
    int i=0,j=0,k=0;
    while(j<N){
        while(A[i]<B[j] && i<N)i++;
        while(C[k]<=B[j] && k<N)k++;
        ans+=(ll)(N-k)*(ll)i;
        j++;
    }
    cout<<ans<<endl;
    return 0;
}