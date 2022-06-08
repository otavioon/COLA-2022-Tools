#include <iostream>
#include <set>

using namespace std;

int main(){
	int N;
	int K;
	int n;
	int num;
	int incre = 1;
  	set<int> m;

  	cin >> N >> K;
  	while(K--){
        cin >> n;
  	    m.insert(n);
    }

  	num = N;

  	while(num){
  	    n = num%10;
        while(m.find(n)!=m.end()){
            n++;
            n = n%10;
            N+=incre;
        }
        incre*=10;
        num = N/(incre);
  	}

    cout << N <<endl;
	return 0;
}
