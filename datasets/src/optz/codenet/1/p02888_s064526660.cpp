//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
using namespace std;
 
int N;
int L[2000];

int ans = 0;
 
void solve(){
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			for(int k=j;k<N;k++){
				if(i!=j && i!=k && k!=j){//互いに異なる棒ならば
					if(L[i]<L[j]+L[k]
					&& L[j]<L[i]+L[k]
					&& L[k]<L[i]+L[j]){
						ans++;
					}
				}
			}
		}
	}
}
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>L[i];

	solve();

	cout<<ans;
	return 0;
}