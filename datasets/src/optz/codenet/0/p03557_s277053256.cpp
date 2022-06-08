#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{ int N; cin >> N;
 vector<long long> A(N); vector<long long>B(N); vector<long long> C(N);
 
 for(int i = 0; i < N; i++){
   cin >> A[i];}
 for(int j = 0; j < N; j++){
   cin >> B[j];}
 for(int k = 0; k < N; k++){
   cin >> C[k];}
 
 long long total = 0;
 
 for(int j = 0; j < N; j++){
   
   auto c1 = lower_bound(A.begin(),A.end(),B[j]);
   auto c2 = upper_bound(B.begin(),B.end(),B[j]);
   
   long long cnt1 = distance(A.begin(),c1);
   long long cnt2 = distance(c2,C.end());
   
   total += cnt1 * cnt2;}
 
 cout << total << endl;
 
 return 0;
}