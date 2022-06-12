#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07.5 07번 O] 가산점 +2 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
			a[i][j] += 2;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
