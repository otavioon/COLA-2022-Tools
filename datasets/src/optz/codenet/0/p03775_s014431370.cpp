#include<iostream>
#include<map>
#include<vector>

using namespace std;

int cnt_digits(long long N){
    int digits=0;
    while(N>0){
      N/=10;
      digits++;
    }
    return digits;
}

int main(){
  long long N,s,j;
  cin >> N;
  int ans=cnt_digits(N);
  vector< pair < long long, long long > > a;
  for(long long i = 1; i < N;i++){
    if(N%i==0){
      j= N / i;
      pair<long long ,long long> p(i , j);
      if(p.first<=p.second){
	s=cnt_digits(p.second);
      }else{
	s=cnt_digits(p.first);
      }
    }
    if(ans>s){
      ans=s;
    }
  }
  cout << ans <<endl;
  return 0;
}