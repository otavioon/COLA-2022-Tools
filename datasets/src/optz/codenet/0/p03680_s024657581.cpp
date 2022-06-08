#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[]){

	int N;
	int a[100000];
	vector<int> b;
	long long int count = 0;
	int now_id;

	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}

	b.push_back(1);
	count++;
	now_id = 1;

	while(1){
		if(a[now_id] == 2){
			cout << count << endl;
			break;
		}
		if(find(b.begin(), b.end(), a[now_id]) == b.end()){
			b.push_back(a[now_id]);
			now_id = a[now_id];
			count++;
		}else{
			cout << -1 << endl;
			break;
		}
	}



	return 0;
}