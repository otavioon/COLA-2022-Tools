// AtCoder140150b.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;


//https://kenkoooo.com/atcoder/#/table/

//テスト
//テスト２

void func150b ()
{
  int n;
  string s;
  cin >> n; //標準入力　cin >> 変数
  cin >> s;

  //ここでsの中にあるABCを数える
  int num = 0;

  //find():部分文字列検索、見つかった先頭の番号を返す
  //substr(n):n番目以降の文字列を取り出す
  while (true) 
  {
	  int temp = s.find("ABC");
	  if (temp == -1) break; //文字列が見つからなかったら抜ける
	  num++;
	  s = s.substr(temp + 2);

  }
  

  cout << num; //標準出力 cout << [表示内容]
}

void func149b ()
{
	long long a, b, k;
	cin >> a;
	cin >> b;
	cin >> k;

	//whileで回したら超時間かかったのでボツ
	if (a >= k) a = a - k;
	else 
	{
		k = k - a;
		a = 0;
		if (b >= k) b = b - k;
		else b = 0;
	}

	cout << a << " " << b;
}

void func148b ()
{
	int n;
	string s, t;
	string new_str = "";

	cin >> n;
	cin >> s;
	cin >> t;

	for (int i = 0; i < n; i++) 
	{
		new_str += s[i];
		new_str += t[i];
	}

	cout << new_str;
}

void func147b ()
{
	int count = 0;
    string s;

	cin >> s;
	int length = (int)s.size();
	for (int i = 0; i < length/2; i++) 
	{
		if (s[i] != s[length - i - 1]) count++;
	}

	cout << count;
}

void func146b ()
{
	int n, length;
	string s;

	cin >> n;
	cin >> s;
	length = s.size();

	//文字コードでA～Zは65～90
	for (int i = 0; i < length; i++)
	{
		//zを超すとき、64+ずらすN-(その文字からZまで進む数)
		if (s[i] + n > 90) printf("%c", 64 + n - (90 - s[i]));
		else               printf("%c", s[i]+n);
	}
	
}

void func145b ()
{
	int n, length;
	int judge = 0;
	string s;

	cin >> n;
	cin >> s;

	length = s.size();
	
	if (length % 2 == 0) {
		for (int i = 0; i < length / 2; i++)
		{
			if (s[i] != s[(length / 2) + i]) break;
			if (i == length / 2 - 1) judge = 1;
		}
	}

	if (judge == 1) cout << "Yes";
	else            cout << "No";
}

void func144b ()
{
	int n;
	int judge = 0;

	cin >> n;

	for (int i = 1; i <= 9; i++) 
	{
		if (n % i != 0) continue;
		if (n / i <= 9) 
		{
			judge = 1;
			break;
		}
	}

	if (judge == 1) cout << "Yes";
	else            cout << "No";
}

void func143b ()
{
	int n;
	int sum = 0;
	int *d; //d[n]のように配列サイズは変数で定義できない

	cin >> n;

	/*
	new演算子:動的にポインタを確保できる
	使い終わったら 「delete[] 【ポインタ名】」
	で確保した領域を削除すること
	*/
	d = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum += d[i] * d[j];
		}
	}

	cout << sum;
	delete[] d;
}

void func142b ()
{
	int n, k;
	int count = 0;
	int *h;

	cin >> n;
	cin >> k;

	h = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		if (h[i] >= k) count++;
	}

	delete[] h;
	cout << count;
}

void func141b ()
{
	int length, judge = 1;
	string s;

	cin >> s;

	length = s.size();
	for (int i = 0; i < length; i++)
	{
		if ((i+1) % 2 == 0 &&  s[i] == 'R' //偶数文字目がR
			|| (i+1) % 2 != 0 && s[i] == 'L'//奇数文字目がL
			) 
		{
			judge = 0;
			break;
		}
	}

	if (judge == 1) cout << "Yes";
	else            cout << "No";
}

void func140b ()
{
	int n, *a, *b, *c;
	int manzoku = 0;
	int pre = -100;

	cin >> n;
	a = new int[n];
	b = new int[n];
	c = new int[n - 1];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n - 1; i++) cin >> c[i];

	for (int i = 0; i < n; i++)
	{
		manzoku += b[a[i] - 1];
		if (pre + 1== a[i]) manzoku += c[pre-1];
		pre = a[i];
	}
	
	delete[] a;
	delete[] b;
	delete[] c;
	cout << manzoku;

}

int main()
{
  //func150b();
  //func149b();
  //func148b();
  //func147b();
  //func146b();
  //func145b();
  //func144b();
  //func143b();
  //func142b();
  //func141b();
	func140b();
  
  return 0;
}