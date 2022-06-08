#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
        while(1){
            vector<int>x(2);
            for(auto&e:x){
                    scanf("%d",&e);
            }
            sort(x.begin(),x.end());
            if(x[0]==0 && x[1]==0) break;
            printf("%d %d\n",x[0],x[1]);
        }
        return 0;
}