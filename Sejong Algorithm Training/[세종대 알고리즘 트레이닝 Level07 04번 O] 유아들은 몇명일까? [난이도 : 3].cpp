#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 04번 O] 유아들은 몇명일까? [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10], cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		if (a[i]>=3 && a[i]<=7) {
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}
