#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,a,b;

    cin >> n >> a >> b;

    vector<int> v(static_cast<unsigned >(n));

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int counter = 0;

    while(1){

        counter++;

        vector<int>::iterator itr = upper_bound(v.begin(),v.end(),b*counter);

        int a_counter = 0;

        for(;itr != v.end(); itr++){
            double d = static_cast<double>((*itr - b*counter)) / static_cast<double>((a-b));
            a_counter += static_cast<int>(ceil(d));
            if(a_counter > counter){
                break;
            }
        }

        if(a_counter <= counter){
            break;
        }
    }

    cout << counter << endl;

    return 0;
}