#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

bool canPay(int num,set<int> banList){
	while(num > 0){
		int digit = num % 10;
		if( banList.count(digit) != 0) return false;
		num /= 10;
	}
	return true;
}

int main()
{
	int N,K;
	cin>>N>>K;
	set<int> banNum;
	for(int i = 0; i < K; i++){
		int num;
		cin>>num;
		banNum.insert(num);
	}
	while(canPay(N,banNum) == false){
		N++;
	}
	cout<<N<<endl;

	return 0;
}
