#include<iostream>
#include<cstring>
#include<map>
using namespace std;

map<string,int> m;
string a,b;

int main(){
	m["1"]=14;
	m["2"]=2;
	m["3"]=3;
	m["4"]=4;
	m["5"]=5;
	m["6"]=6;
	m["7"]=7;
	m["8"]=8;
	m["9"]=9;
	m["10"]=10;
	m["11"]=11;
	m["12"]=12;
	m["13"]=13;
	cin >> a;
	cin >> b;
	if (m[a]>m[b]) cout << "Alice";
	else if (m[a]<m[b]) cout << "Bob";
	else cout << "Draw";
	return 0;
}