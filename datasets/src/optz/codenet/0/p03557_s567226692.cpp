//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
// 1. dpを書く
// 2. nを書く
int N;
ll A[10001],B[100001],C[100001];
// 7. calcを書く
ll calcA(ll lb,ll ub,ll k){
	ll mid=(lb+ub)/2;
	if(ub-lb<2){
		if(A[ub]<k)return ub;
		return lb;
	}
	if(A[mid]<k){
		lb=mid;
	}else{
		ub=mid;
	}

	return calcA(lb,ub,k);
}
ll calcC(ll lb,ll ub,ll k){
	ll mid=(lb+ub)/2;
	if(ub-lb<2){
		if(C[ub]>k)return ub;
		return lb;
	}
	if(C[mid]>k){
		lb=mid;
	}else{
		ub=mid;
	}

	return calcC(lb,ub,k);

}


int main() {
	cin>>N;

	//3.初期化

	//4.入力
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		cin>>B[i];
	}
	for(int i=0;i<N;i++){
		cin>>C[i];
	}

	//5.並び替え
	sort(A,A+N);
	sort(C,C+N, greater<ll>() );

	//6.出力

	ll total=0;
	for(int i=0;i<N;i++){
		//B[i]より小さいAの数
		//B[i]より大きいCの数
		//totalに足す
		total+=(calcA(0,N-1,B[i])+1)*(calcC(0,N-1,B[i])+1);

	}

	cout<<total<<endl;

	return 0;
}
