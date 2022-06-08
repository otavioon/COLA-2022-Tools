#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int N, count = 0;
	vector<int> T;
	vector<vector<int>> S;
	
	cin >> N;
	
	//入力値の取得
	for(int i = 0; i < N; i++){
		int t;
		cin >> t;
		T.push_back(t);
	}
	
	//階乗分回す
	for(int i = 0; i < N - 2; i++){
		for(int j = i + 1; j < N - 1; j++){
			for(int k = j + 1; k < N; k++){
				vector<int> tmp;
				tmp.push_back(i);
				tmp.push_back(j);
				tmp.push_back(k);
				S.push_back(tmp);
			}
		}
	}
	
	//カウントする
	for(int i = 0; i < S.size(); i++){
		int a = S[i][0];
		int b = S[i][1];
		int c = S[i][2];
		
		if(a < b + c && b < c + a && c < a + b){
			count++;
		}
	}
	
	cout << count << endl;
	
	return 0;
}