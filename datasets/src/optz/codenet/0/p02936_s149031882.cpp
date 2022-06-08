#include <iostream>
#include <vector>

using namespace std;
typedef struct {
   int p;
   int x;
} pxdata;

vector <int> *tree;
int *counter;

void func( int p, int x )
{
    counter[p] += x;
//    cout << "add [" << p << "]+" << x << endl;
    for ( int i = 0; i < tree[p].size(); i ++ ) {
        func( tree[p][i], x );
    }

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
        tree[a].push_back( b );
    }

    for ( int i = 0; i < N; i ++ ) {
        cout << i << ":" ;
        for ( int j = 0; j < tree[i].size(); j ++ ) {
            cout << tree[i][j];
        }
        cout << endl;
    }



    pxdata px[Q];

    for ( int i = 0; i < Q; i ++ ) {
        cin >> px[i].p >> px[i].x;
    }

    for ( int i = 0; i < Q; i ++ ) {
        cout << px[i].p << " " << px[i].x << endl;
    }

    for ( int i = 0; i < Q; i ++ ) {
        int p = px[i].p-1;
        int x = px[i].x;

        func( p, x );
    }

    for ( int i = 0; i < N; i ++ ) {
        cout << counter[i] << " ";
    }
    cout << endl;

    return 0;

}