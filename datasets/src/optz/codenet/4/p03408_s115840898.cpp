#include <bits/stdc++.h>

using namespace std ;

#define sz(v) (int)v.size()
#define ll long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pf push_front
#define pb push_back
#define fast FastInputOutput() ;
#define Clear( container , value ) memset( container , value , sizeof container )
#define PI acos( -1.0 )
#define forn( t , v , be , n ) for( t v = be ; v < n ; v++ )
#define fore( x , j ) for( auto x : j )
#define se second
#define fr first
//#define c_b fflush(stdin);

const ll Long_max = numeric_limits < ll > :: max() ;
const int Int_max = numeric_limits < int > :: max() ;

int dx[ ] = { 1, -1, 0, 0, 1, -1, -1, 1 } ;
int dy[ ] = { 0, 0, -1, 1, 1, -1, 1, -1 } ;

void File_input( string pathIn ) {
    freopen( pathIn.c_str(), "r", stdin ) ;
}

void File_output( string pathOut ) {
    freopen( pathOut.c_str(), "w", stdout ) ;
}

int msg() {
    srand( time( 0 ) ) ;
    vector < string > st = {
        "Wish everyone high ratings!",
        "Good luck!",
        "Have fun!",
        "Please, read all the problems!",
        "Go Go fight!"
    } ;
    cerr << st[ rand() % sz( st ) ] ;
    return 0 ;
}


void FastInputOutput() {
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}

int n , k ;
string str ;
set < string > ap ;
map < string , int > a_fr , b_fr ;

int main(){

   ap.insert("1") ;
   cin >> n ;
   forn( int , i , 0 , n ){
      cin >> str ;
      ap.insert( str ) ;
      a_fr[ str ]++ ;
   }

   cin >> k ;
   forn( int , i , 0 , k ){
      cin >> str ;
      b_fr[ str ]++ ;
   }

   int mx = -Int_max ;

   fore( i , ap ){
     int sum = a_fr[ i ] - b_fr[ i ] ;
     mx = max( sum , mx ) ;
   }


   cout << mx ;


}
