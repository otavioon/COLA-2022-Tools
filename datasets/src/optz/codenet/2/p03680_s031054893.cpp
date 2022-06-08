#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int cunt;
int main(){
    int N;
    cin>>N;
    
    a.push_back(-1);

    int ac;
    for(int i=1;i<=N;i++){
        cin>>ac;
        a.push_back(ac);
    }
    int c=1;
    while(c!=2){
         c=a[c];
         cunt++;
         if(c==1||cunt>N){
            cout<<-1<<"\n"; 
            return 0;
         } 
    }
    cout<<cunt<<"\n";

    return 0;

}