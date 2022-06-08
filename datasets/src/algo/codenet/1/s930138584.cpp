#include<iostream>
using namespace std;

int main(){
	int dif,check=0;
	int array[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)cin >>array[i][j];
		if(i>=1){
			dif=array[i][0]-array[0][0];
			for(int k=0;k<3;k++){
				if(dif!=array[i][k]-array[0][k])check=1;
			}
		}
	}
	if(check==1)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;

}