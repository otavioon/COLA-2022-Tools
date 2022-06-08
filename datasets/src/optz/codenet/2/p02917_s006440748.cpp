#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> B(N-1);
  for(int i = 0; i < N - 1; ++i)
  {
    cin >> B[i];
  }
  
  vector<int> A(N);
  int temp = 0;
  for(int i = 0; i < N - 1; ++i)
  {
    if(i == 0)
    {
      A[i] = B[i];
      continue;
    }
    else
    {
      A[i] = B[i-1];
      if(A[i] > B[i])
      {
        A[i] = B[i];
      }
    }
  }
  A[N-1] = B[N-2];
  
  cout << accumulate(A.begin(), A.end(), 0) << endl;
  return 0;
}
