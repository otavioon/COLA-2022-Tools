#include<iostream>
using namespace std;
int main(){
	int A,B;
	cin>>A>>B;
	while (A<1 or A>13 or B<1 or B>13){
		cin>>A>>B;
	}
	
	if(A==1){
		A=14;
	}
	else if(B==1){
		B=14;
	}
		
	if(A>B){
		cout<<"Alice";
	}
	else if(A<B){
		cout<<"Bob";
	}
	else{
		cout<<"Draw";
	}
}