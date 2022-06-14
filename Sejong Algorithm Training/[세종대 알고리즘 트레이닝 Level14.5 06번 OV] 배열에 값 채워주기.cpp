#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14.5 06번 OV] 배열에 값 채워주기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
void Magic(int a[5][5]) {
	int n = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			a[i][j] = n;
			n++;
		}
	}
}

void OutPut(int a[5][5]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 0) {
				cout << " ";
			}
			else { cout << a[i][j]; }
		}cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int a[5][5] = { 0 };
	Magic(a);
	OutPut(a);
	return 0;
}
