#include <iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<array>
#include<functional>
#include<iomanip>
#include<ios>
using namespace std;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)

typedef int value_type; /* ソートするキーの型 */

value_type med3(value_type x, value_type y, value_type z)
/* x, y, z の中間値を返す */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
        if (z < y) return y; else if (x < z) return x; else return z;
}

void quicksort(value_type a[], int left, int right,value_type index[])
/* クイックソート
 * a     : ソートする配列 
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 * index: index配列
 */
{
    if (left < right) {
        int i = left, j = right;
        value_type tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2ではオーバーフローしてしまう */
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
            while (pivot < a[j]) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i],a[j] を交換 */
            tmp = index[i]; index[i] = index[j]; index[j] = tmp;
            i++; j--;
        }
        quicksort(a, left, i - 1,index);  /* 分割した左を再帰的にソート */
        quicksort(a, j + 1, right,index); /* 分割した右を再帰的にソート */
    }
}


int dfs(int n,int N){
    if (n>N){
        return 0;
    }
    

    int ret;
    
    return ret;
}
int main(){
    string A,B;
    cin >>A >>B;

    string ans;

    
    
    if(A[0]==B[2] && A[1]==B[1] && A[2]==B[0]){
        ans="YES";
    }else{
        ans="NO";
    }

    cout<<ans<<endl;


    return 0;
}