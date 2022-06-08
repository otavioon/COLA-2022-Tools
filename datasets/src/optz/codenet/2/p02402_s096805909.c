#include <stdio.h>
#include <string.h>
int main(){
  char line[100];				/* コマンドラインからの入力 */
  int num;						/* 整数の数 */
  char *tok_ptr;				/* strtokで使う(文字列の整数の)ポインタ */
  int list[num];				/* 整数を入れる箱 */
  int i;						/* 添字 */
  int min=1000000, max=-1000000, sum=0;
  /* 入力していく整数の数の入力 */
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &num);
  /*  */
  fgets(line, sizeof(line),stdin);
  tok_ptr=strtok(line, " ");
  for(i=0; i<num; ++i){
	if(tok_ptr==NULL)
	  break;
	sscanf(tok_ptr, "%d", &list[i]);
	sum=sum+list[i];
	if(min>list[i])
	  min=list[i];
	if(max<list[i])
	  max=list[i];
	tok_ptr=strtok(NULL, " ");
}
  printf("%d %d %d\n", min, max, sum);
  return 0;
}


