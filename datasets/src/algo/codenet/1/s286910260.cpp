#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b1,b2,b3;
	cin >> b1 >> b2 >> b3;

	int x,y,z;
	for(int i=0;i<2;i++){
		cin >> x >> y >> z;
		if(x-b1 != y-b2 || x-b1 != z-b3){
			cout << "No\n";
			return 0;
		}
	}		
	cout << "Yes\n";

	return 0;
}