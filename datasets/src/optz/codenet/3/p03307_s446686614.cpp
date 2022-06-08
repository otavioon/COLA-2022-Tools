#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
	int N;
  cin >>N;
  vector<int> A;
  for(int i=0;i<N;i++)cin >>A[i];
  for(int i=0;i<N;i++)A[i]=abs(A[i]);
  sort(A.begin(),A.end());
  cout << A[N-1]-A[0] <<endl;
  
    
}