#include <iostream>
#include <vector>

using namespace std;
typedef struct {
   int p;
   int x;
} pxdata;

vector <int> *tree;
int *counter;

int func( int p )
{
    int c = counter[p];

//    cout << p << " add " << counter[p] << endl;

    if ( tree[p].size() ) c += func( tree[p][0] );

    return c;
}

int main()
{
    int N, Q;

    cin >> N;
    cin >> Q;

    tree = new vector<int> [N];
    counter = new int[N];
    // vector<int> tree[N]; 
    // int counter[N];

    fill( counter, counter+N, 0 );

    int a, b;
    for ( int i = 0; i < N-1; i ++ ) {
        cin >> a;
        cin >> b;

        a--;
        b--;
        tree[b].push_back( a );
    }


    pxdata px[Q];

    for ( int i = 0; i < Q; i ++ ) {
        cin >> px[i].p >> px[i].x;
    }

    for ( int i = 0; i < Q; i ++ ) {
        int p = px[i].p-1;
        int x = px[i].x;

        counter[p] += x;
    }

///    for ( int i = 0; i < N; i ++ ) {
//        cout << i << ":";
//        for ( int j = 0; j < tree[i].size(); j ++ ) {
//            cout << tree[i][j] << " ";
//        }
//        cout << endl;
//    }


    for ( int i = 0; i < N; i ++ ) {
        cout << func(i) << " ";
    }
    cout << endl;

    return 0;

}