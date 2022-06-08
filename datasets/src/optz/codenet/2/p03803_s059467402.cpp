#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B;
	cin>>A>>B;
	if(A<14||B<14){
	if(A==1){
		if(A==B)
			cout<<"Draw";
		else if(B==1)
			cout<<"Bob";
		else 
			cout<<"Alice";
	}
	else
	if(A>B)
		cout<<"Alice";
	else if(B>A)
	cout<<"Bob";
	else if(B==A)
	cout<<"Drawa";
		}

	}