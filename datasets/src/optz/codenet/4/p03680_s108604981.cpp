#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int i,count=1;
    for(i=0;i<n;i++)
        cin >> a[i];
    int tmp = a[0];
    if(tmp==2)
        cout << count << endl;
    if(tmp!=2){
        for(i=1;i<n;i++){
            tmp = a[tmp-1];
            count++;
            if(tmp==2){
                cout << count << endl;
                break;
            }   
        
        }
    }
    if(count==n || tmp!=2)
        cout << -1 << endl;
}