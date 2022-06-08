#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
using ll = long long;
using ld = long double;
using namespace std::chrono; 
#define fo(i,z,n) for(int i = z;i<n;i++)
#define Fo(i,z,n) for(ll i = z;i<n;i++)
#define INT_BITS 32
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> > 
#define pb push_back
#define f first
// #define s second
#define int long long
#define all(c) (c).begin(), (c).end()
#define endl '\n'
// auto start = high_resolution_clock::now(); 
// auto stop = high_resolution_clock::now(); 
// auto duration = duration_cast<microseconds>(stop - start); 
 
// cout << duration.count() << endl; 
int ceil(int a,int b){
	if(a%b == 0)return a/b;
	else return a/b+1;
}


bool check(int* arr,int mid ,int k,int n){
	int r = 0;
	fo(i,0,n){
		r += ceil(arr[i],mid)-1;
	}
	if(r <= k)return true;
	else return false;
}



int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
     // int t;
     // cin >> t;

     // while(t--){

 
     // }

     int n,k;
     cin >> n >> k;
     int arr[n];
     fo(i,0,n)cin >> arr[i];
sort(arr,arr+n);

int l = 0;
int r = arr[n-1];
int ans = -1;
while(l <= r){
	int mid = (l+r)/2;
	if(check(arr,mid,k,n)){
		ans = mid;
		r = mid-1;
	}
	else l = mid+1;
}

cout << ans << endl;

     

return 0;
}

