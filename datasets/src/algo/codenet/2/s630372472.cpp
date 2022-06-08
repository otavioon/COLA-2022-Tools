#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int temp,cnt=0;
	multiset<int> s;
	for(temp=0;temp<n;temp++) {
		int x;
		cin>>x;
		s.insert(x);
	}

	while(s.size()>1) {
		auto it=s.end();
		it--;
		int num=*it;
		s.erase(it);
		//cout<<num<<"\n";
		int cur=1;
		for(int temp=0;temp<30;temp++) {
			if(s.find(cur-num)!=s.end()) {
				cnt++;
				s.erase(s.lower_bound(cur-num));
				break;
			}
			cur=cur*2;
		}
	}
	cout<<cnt<<"\n";

}