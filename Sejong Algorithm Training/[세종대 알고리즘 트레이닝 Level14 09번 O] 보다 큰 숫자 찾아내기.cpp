#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14 09번 O] 보다 큰 숫자 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10] = { 10,50,40,20,30,40 };
int input[10];
int cnt[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 6; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (a[j] > input[i]) {
				cnt[i]++;
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		cout << input[i] << "=" << cnt[i] << "개" << '\n';
	}
	return 0;
}
