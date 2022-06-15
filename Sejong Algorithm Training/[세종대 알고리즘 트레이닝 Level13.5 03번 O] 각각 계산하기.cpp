#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 03번 O] 각각 계산하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10], b[10], c[10];
int result[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < 5; i++) {
		result[i] = a[i] * b[i] + c[i];
		cout << result[i] << " ";
	}
	return 0;
}
