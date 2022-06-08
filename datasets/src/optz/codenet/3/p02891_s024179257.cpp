#include <iostream>
#include <string>
#include <stack>
using namespace std;
char a[200];
int n;
stack<int> s;
int main(){
    string b;
    unsigned long long k;
    cin >> b >> k;
    n = b.length();
    for(int i = 0;i<b.length();i++){
        a[i] = b.at(i);
      //cout << a[i] << endl;
    }
    int count = 0;
  	int j = 0;
  	int c[200] = {};
    for(int i = 0;i<b.length() - 1;i++){
        /*if(i == s.length()){
            if(a[i] == a[0]){
                count++;
                s.push(count);
                count = 0;
            }else{
                s.push(count);
                count = 0;
            }
        }else{*/
            if(a[i] == a[i+1]){
              
                count++;
                //continue;
            }else{
              //cout << count << endl;
                c[j] = count;
              	j++;
                count = 0;
            }
        //}
    }
  
    c[j] = count;
    unsigned long long ans = 0;
    for(int i = 0;i<100;i++){
      	//cout << c[i] << endl;
        if (c[i] == 0){
            //s.pop();
            continue;
        }
        ans += (c[i]+ 1) / 2;
        //s.pop();
    }
  	
    ans *= k;
    if (c[0] % 2 == 0 && c[j] % 2 == 0 && a[0] == a[n-1]){
      ans += k-1;
    }
    cout << ans << endl;
    

}
