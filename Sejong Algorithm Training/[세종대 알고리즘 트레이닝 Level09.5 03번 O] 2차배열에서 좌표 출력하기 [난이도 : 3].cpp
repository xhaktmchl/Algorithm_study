#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 03번 O] 2차배열에서 좌표 출력하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10][10] = {
	"DAA",
	"BCD",
	"EFA",
	"AAD",
	"FGE"
};
char ch;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> ch;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == ch) {
				cout << "(" << i << "," << j << ")" << '\n';
			}
		}
	}
	return 0;
}
