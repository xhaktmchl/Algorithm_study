#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12 02번 V] 두 문장의 길이는?
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10], b[10];
int idxA = 0,idxB=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;

	for (int i = 0; i < 10; i++) {
		if (a[i] == '\0') { break; }
		idxA++;
	}
	for (int i = 0; i < 10; i++) {
		if (b[i] == '\0') { break; }
		idxB++;
	}

	cout << idxA << " " << idxB;
	return 0;
}
