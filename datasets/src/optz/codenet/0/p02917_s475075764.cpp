    #include<iostream>
    #include<cmath>
    using namespace std;

    int main(){
        int n;
        int b[200];

        cin >> n;
        for(int i = 1; i <= n-1; i++) cin >> b[i];
        // cout << endl ;

        int ans = 0;
        int tmp = 0;
        for(int i = n-1;; i--){
            if(b[i] <= b[i+1] || i == n-1){
                ans += b[i];
                tmp = b[i];
                // cout << "b[" << i << "] is " << b[i] << " b[" << i+1 << "] is " << b[i+1] << endl;
                // cout << "if " <<tmp << endl;
            } else {
                ans += b[i+1];
                tmp = b[i+1];
                // cout <<"else " << tmp << endl;

        }
        if(i == 1){  
            // cout << "tmp is " << tmp << " b[0] is " << b[1] << endl;
            if(tmp < b[1]){
                ans += b[1];
                // cout << "if " << b[1] << endl;
            } else {
                ans += tmp;  
                // cout << "else " << tmp << endl;
            } 
            // cout << tmp << endl;
            break;
        }
        }
        cout << ans << endl;
    }