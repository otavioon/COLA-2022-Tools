#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int N;
    long M, Q;
  	cin >> N >> M >> Q;
    typedef pair<int,int> pair;
    vector<pair> LR;
    vector<pair> pq;
    int AN[501][501];
    long SUM[501][501];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            AN[i][j]=0;//syokika
        }
    }
    int tmp,tmp2;
    for(long i=0;i<M;i++){
        cin >> tmp >> tmp2;
        AN[tmp][tmp2]++;
    }
    
    //2jigenruisekiwa
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) AN[i][j] += AN[i][j - 1]; 
        
    }
	for (int i = 1; i <= N; i++) {
	    for (int j = 1; j <= N; j++) AN[i][j] += AN[i - 1][j];
    }
  
 	int L,R;
    for(long i=0;i<Q;i++){
        cin >> L >> R;
        cout << AN[R][R] + AN[L - 1][L - 1] - AN[L - 1][R] - AN[R][L - 1] << endl;
    }
    return 0;
}






