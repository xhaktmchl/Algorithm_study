#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 09번 O] 여러 문장 하드코딩 후 출력하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
string str[5] = {
	"BBQWORLD","KFCAPPLE","LOT"
};
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == ch) { cnt++; }
		}
	}

	cout << cnt;
	return 0;
}
