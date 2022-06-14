#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14 06번 O] 같은번호 개수 세기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int vect[10] = { 3,5,1,1,2,3,2 };
int a[5];
int cnt[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			if (vect[j] == a[i]) { cnt[i]++; }
		}	
	}

	for (int i = 0; i < 4; i++) {
		cout << a[i] << "=" << cnt[i] << "개" << '\n';
	}
	return 0;
}
