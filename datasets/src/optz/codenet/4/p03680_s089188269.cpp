#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> vec(N, 0);

    for(int i = 0; i < N; i++){
	int a;
	cin >> a;
	vec.at(i) = a;
    }

    vector<bool> pushed(N, false);
    int pt = 1;
    int sum = 0;
    for(;;){
	int npt = vec.at(pt-1);
	sum++;
	if(npt == 2){
	    cout << sum << endl;
	    break;
	}else if(pushed.at(npt-1)){ // loop
	    cout << -1 << endl;
	    break;
	}
	pushed.at(npt-1) = true;
	pt = npt;
    }
    
    return 0;
}
