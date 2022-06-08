/*
問題文
AliceとBobは、2人で1枚ポーカーを行います。
1枚ポーカーは、トランプを用いて行う2人ゲームです。

今回使用するトランプでは、各カードに 1 から 13 までの数が書かれています。
カードの強さは、カードに書かれている数で決まり，強さの基準は以下の通りです。
弱 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < 11 < 12 < 13 < 1 強

1枚ポーカーは以下の手順で行います。

各プレイヤーは、トランプからカードを1枚選んで、自分の手札とします。
両プレイヤーは、手札を見せ合います。強いカードを持っているプレイヤーが勝ちです。
なお、両プレイヤーの持っているカードの強さが同じ場合は引き分けです。
2人の対戦を眺めていたあなたは、AliceとBobの手札を知ることができます。
Aliceが持っているカードに書かれている数は A 、Bobが持っているカードカードに書かれている数は B です。
2人の代わりに、勝敗を判定するプログラムを作ってください。
*/

#include<iostream>
#include<map>
#include<string>

//mapってどこで使うのかわからなかったので、mapが使えた事とこの発想が自力で出てきて嬉しい
//がもっと頭の良い方法ないですか…

//ある程度順序に従った数値の強さ比べ

int main() {
	const int max = 13; //使用するトランプは13枚より　13
	const int singularity = 1; //今回はポーカーなので1が特異性　大富豪の場合には2が一番強いので2をここに代入する
	const int adjustment = 1;  //トランプは１から始まるので0から始めるプログラムに調節する(1から始めてもいいですがint i=1ってかっこ悪いので却下 int i=0)

	int alice, bob;
	std::string result;
	std::map<int,int> mp;

	for (int i = max; i > 0;i--) {
		if (i > singularity) {
			mp[i] = i - singularity - adjustment;  //max==13から減っていき
		}
		else {
			mp[i] = max + i - singularity - adjustment;      //singularityより数値が小さい方とき、現在ある最大の数値の次の数値を代入する　ポーカー(const int singularity = 1)の時、「１」の強さが「12(0～12の13枚のうち最強)」　大富豪(const singularity = 2)の時、「1」の強さが「11(0～12の13枚のうち二番目に強い)、「2」の強さが「12(0～12の13枚のうち最強)」
		}
	}

	/*
	for (auto&& x : mp) {
		std::cout<<x.first<<" "<<x.second<<std::endl; //mpの確認
	}
	*/

	std::cin >> alice >> bob;

	mp[alice]>mp[bob]? result = "Alice" : mp[alice] < mp[bob] ? result = "Bob" : result = "Draw";

	std::cout << result << std::endl;

	return 0;
}


//手動git_ver_1
/*
mp[2] = 0;
mp[3] = 1;
mp[4] = 2;
mp[5] = 3;
mp[6] = 4;
mp[7] = 5;
mp[8] = 6;
mp[9] = 7;
mp[10] = 8;
mp[11] = 9;
mp[12] = 10;
mp[13] = 11;
mp[1] = 12;
*/