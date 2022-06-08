#include<iostream>
using namespace std ;

int main(){
	int x,y ;
	while(1){
		cin >> x >> y ;
		if(x==0&&y==0) break ;
		if(x>y){
			x = x-y ;
			y = y+x ;
			x = y-x ;
		}
		cout << x << " " << y << endl ;
	}
}
