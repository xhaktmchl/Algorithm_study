#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07.5 05번 O] 풍성한 대문자들 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') { cnt++; }
	}
	
	if (cnt >= 3) { cout << "풍족하다"; }
	else if (cnt >= 1) { cout << "적절하다"; }
	else { cout << "부족하다"; }
	return 0;
}
