#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 06번 O] 연속된 값 세팅하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;

		for (int j = start; j <= end; j++) {
			a[j]++;
		}
	}

	for (int i = 0; i < 9; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
