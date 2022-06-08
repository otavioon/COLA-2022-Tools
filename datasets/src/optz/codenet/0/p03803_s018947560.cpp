
#include <iostream>

using namespace std;

int N, M;
const int N_max = 50;
const int M_max = 50;
char A[N_max][N_max], B[M_max][M_max];

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			cin >> B[i][j];
		}
	}

	bool ans = false;
	bool match;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(i+M-1 >= N || j+M-1 >= N){
				continue;
			}

			match = true;
			for(int y = 0; y < M; y++){
				for(int x = 0; x < M; x++){
					if(A[i+y][j+x] != B[y][x]){
						match = false;
						break;
					}
				}
			}
			if(match == true){
				ans = true;
				break;
			}
		}
		if(ans == true){
			break;
		}
	}

	if(ans == true){
		cout << "Yes" << endl;
	}else{
		cout << "No" <<endl;
	}


	return 0;
}