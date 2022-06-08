#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1.0);
const double eps=1e-11;

#define size(A) ((int)A.size())
#define length(A) ((int)A.length())
#define mp(A,B) make_pair(A,B)
#define pb(x) push_back(X);

using int64=long long int;
using ipair=pair<int,int>;
using vi=vector<int>;
using vd=vector<double>;

int n,k,d;
set<int> s;

int f(int num){
	while(num){
		d=num%10;
		num/=10;
		if(s.count(d)==1){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>d;
		s.insert(d);
	}
	while(true){
		if(f(n)){
			cout<<n<<endl;
			break;
		}
		++n;
	}
}