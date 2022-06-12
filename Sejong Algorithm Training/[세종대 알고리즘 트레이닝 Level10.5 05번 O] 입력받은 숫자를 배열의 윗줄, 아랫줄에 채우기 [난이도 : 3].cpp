#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 05번 O] 입력받은 숫자를 배열의 윗줄, 아랫줄에 채우기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n1, n2, n3;
int a[5][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < 4; i++) {
		a[0][i] = n1++;
	}
	for (int i = 0; i < 4; i++) {
		a[1][i] = n2++;
	}
	for (int i = 0; i < 4; i++) {
		a[2][i] = n3++;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
