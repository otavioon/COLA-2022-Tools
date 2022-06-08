#include<iostream>
#include<string>
using namespace std;
int main(){
	string S;
	long K,sum=0;
	int len,equal,count=0,countL;
	int firstC,middleC,lastC;
	bool first=false;
	cin>>S>>K;
	len = S.length();
	equal=1;
	for(int i=1;i<len;i++){
		if(S[i]==S[i-1]){
			equal++;
		}else{
			if(first==false){
				count=equal;
				first=true;
				equal=1;
			}
			if(equal>=2&&equal%2==0){
				sum+=equal/2;
				equal = 1;
			}else if(equal>=2&&equal%2==1){
				sum+=(equal-1)/2;
				equal = 1;
			}else equal = 1;
		}
	}
	countL=equal;
	firstC = sum+(count-count%2)/2;
	if(S[0]==S[len-1]){
		middleC = sum+((count+countL)-(count+countL)%2)/2;
	}else{
		middleC = sum+(count-count%2)/2+(countL-countL%2)/2;
	}
	lastC = middleC+(countL-countL%2)/2;
	if(K==1){
		if(countL>=2&&countL%2==0)sum+=countL/2;
		else if(countL>=2&&countL%2==1)sum+=(countL-1)/2;
		if(count>=2&&count%2==0)sum+=count/2;
		else if(count>=2&&count%2==1)sum+=(count-1)/2;
	}else sum = firstC+middleC*(K-2)+lastC;
	cout<<sum;
	return 0;
}