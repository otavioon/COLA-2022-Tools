#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll valid(vector<int>vec,int val){
    ll sum=0;
    for(int i=0;i<vec.size();i++)
        sum+=abs(vec[i]-(val+i+1));
    return sum;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a;
    cin>>a;
    vector<int>vec(a);
    for(int i=0;i<a;i++){
        cin>>vec[i];
    }
    int s=0,e=1e9;
    ll ans=1e18;
    while(s<=e){
        int mid=(s+e)/2;
        ll j=valid(vec,mid);
        if(j<ans){
            ans=j;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    s=-1e9,e=0;
    ll ans1=1e18;
    while(s<=e){
        int mid=(s+e)/2;
        ll j=valid(vec,mid);
        if(j<ans1){
            ans1=j;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<min(ans,ans1)<<endl;
}