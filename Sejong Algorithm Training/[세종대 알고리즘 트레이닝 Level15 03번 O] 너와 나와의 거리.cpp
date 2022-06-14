#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 03번 O] 너와 나와의 거리
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < 6; i++) {
		if (abs(a[i] - a[i - 1]) >= 3) {
			flag = 0;
			break;
		}
	}

	if (flag == 1) {
		cout << "완벽한배치";
	}
	else { cout << "재배치필요"; }
	return 0;
}
