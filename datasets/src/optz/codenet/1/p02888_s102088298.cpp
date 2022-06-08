#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
  
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}
  
int main()
{
  int i,j,right,third;
  ll tmp;
  int N; cin >> N;
  int L[1001] = {0};
  int LS[1001] = {0};
  ll ans = 0;

  rep(i,N){
      cin >> tmp;
      L[tmp]++;
  }
  repd(i,1,1001){
      LS[i] = LS[i-1] + L[i];
  }

  repd(i,1,1001){
    if(L[i]>=3){ans += L[i] * (L[i]-1) * (L[i]-2) / 6;}
  }

  repd(i,1,1001){
    ans += L[i] * (L[i] - 1) / 2 * (LS[min(2*i-1,1000)] - L[i]);
  }

  repd(i,1,1001){
      if(L[i]<=0){continue;}
      repd(j,i+1,1001){
          if(L[j]<=0){continue;}
          right = min(i + j - 1,1001);
          third = LS[right] - LS[j];
          tmp = L[i] * L[j] * third;
          ans += tmp;
      }
  }
  cout << ans << endl;

  return 0;
}
