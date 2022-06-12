#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 11번 O] 암호문자 출력하기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5];
char result[5][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 0) { result[i][j] = '!'; }
			else if (a[i][j] % 2 == 0) { result[i][j] = '#'; }
			else if(a[i][j]%2==1){ result[i][j] = '@'; }
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << result[i][j];
		}cout << '\n';
	}
	return 0;
}
