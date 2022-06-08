#include<bits/stdc++.h>

using namespace std;
#define Pi acos(-1)
#define _terminated return 0
#define endl "\n"
#define yes cout << "Yes" << endl 
#define no cout << "No" << endl 
#define booster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<long> > v2l;

const int mod = 1e+5;
const int mx = 2e+5;
const ll inf = 1e18;

void upper_bubble_sort(){
     int i,j,temp,number_of_input;
     int array[100];
     cin >> number_of_input;
     for(i=0; i<number_of_input; i++)
         cin >> array[i];
         for(i=0; i<number_of_input; i++){
             for(j=0; j<(number_of_input-i-1); j++){
               if(array[j] > array[j+1]){
                 temp = array[j];
                 array[j] = array[j+1];
                 array[j+1] = temp;
                }
              }
         }
    for(i=0; i<number_of_input; i++)
      cout << array[i] << endl;
}
void bst(void){
          int low,high,mid,keynum,num,array[100];
          cin >> keynum;
          low = 1;
	         high = num;
         	do{
		        mid = (low + high) / 2;
		         if(keynum < array[mid])
			         high = mid - 1;
		         else if (keynum > array[mid])
			         low = mid + 1;
	         } 
          while (keynum != array[mid] && low <= high);
	        if(keynum == array[mid]){
            cout << "number located at " << mid +1 << endl;}
         else
           no;
}

void solvio(void){
     int k,x;
     cin >> k >> x;
     int temp = 500*k;
     if(temp >= x) yes;
     else no;
}

int main(){
    booster;
    solvio();
    _terminated;
} 