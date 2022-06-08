#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

int main(){
	string s;	long long k, ans = 0;
  	cin >> s >> k;
  	char stmp = s[0];
  	int itmp = 1;
  	for(size_t i = 1; i <= s.size(); i++){
      	if(i == s.size()){
          ans += itmp/2;
          break;
        }
     	else if(stmp == s[i]){
          itmp++;
        }
      	else{
          ans += itmp/2;
          itmp = 1;
          stmp = s[i];
        }
    }
  
  	if(s.size() == 1)
      	cout << (k+1)/2 << endl;
 	else{
      if(itmp = s.size() && s.size()%2 == 1){
        long long odd = (k+1)/2;
        long long even = k - odd;
        long long size = s.size();
        cout << (size+1)/2*odd + size/2*even << endl;
      }
      else
  		cout << ans*k << endl;
    }
}