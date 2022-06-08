#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define ll long long

int main(){

    int x, y;
    queue<int> left;
    queue<int> right;

    while(1){
        cin >> x >> y;
        if((x ==0) && (y == 0)){
            break;
        }
        left.push(x);
        right.push(y);
    }    

    int length = left.size();

    for(int i=0; i<length; i++){
        if(left.front() > right.front()){
            cout << right.front() << " " << left.front() << endl;
        }else{
            cout << left.front() << " " << right.front() << endl;
        }
        left.pop();
        right.pop();

    }

    return 0;
}