#include <stdio.h>
int main()
{
  int n, m, i, j, x;
  long  sum=0;
  //配列の大きさw設定
  scanf("%d", &n);
  long a[n];
      //配列に値を入れる
      for(m = 0; m < n; m++){
          scanf("%ld", &a[m]);
          //合計の計算
          sum = sum + a[m];
      }

  //配列の並び換え（大きい順）
  for(i=0; i < n ;i++){
    for(j = i+1; j < n ;j++){
      if(a[i] > a[j]){
	x = a[i];
        a[i] = a[j];
        a[j] = x;
      }
    }
  }
  n--;
  //計算結果の出力
  printf("%d %d %d\n", a[0], a[n], sum);
  return 0;
}