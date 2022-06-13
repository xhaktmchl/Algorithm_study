#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 06번 O] 문장의 길이 구하기2
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char v[102];
int idx = -1;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> v;
	for (int i = 0; i < 100; i++) {
		if (v[i] == 0) {
			idx = i;
			break;
		}
	}

	for (int i = 0; i < idx; i++) {
		if (v[i] == v[idx - 1]) { cnt++; }
	}

	cout << idx << '\n' << cnt;
	return 0;
}
