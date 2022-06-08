#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
#define sz              3000005
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string s,p;
int arr[sz];

bool check(int n, int k, int mid){
    if(mid==0)return true;
    for(int i=1; i<=n; i++){
        if(arr[i]<=mid)continue;
        if(arr[i]/mid>k)return false;
        if(arr[i]>mid){
            k-=(arr[i]/mid);
        }
    }
    return true;
}

int solve(int n, int k){

    int lo=0;
    int hi=1e10;

    while(hi-lo>2){

        int mid=(lo+hi)/2;
        if(check(n,k,mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    while(hi and check(n,k,hi-1))hi--;
    return hi;
}

int main(){
    Fast;
    int a,b,c, i,j,k, n,m,t, cs=1;

    cin>>n>>k;
    for(i=1; i<=n; i++)cin>>arr[i];

    cout<<solve(n, k)<<endl;

    return 0;
}

