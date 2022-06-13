#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11.5 09번 O] 다른 배열에 값 옮기기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5],b[10];
int idx = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 1; i >=0; i--) {
		for (int j = 2; j >=0; j--) {
			cin>>a[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[idx++] = a[i][j];
		}
	}

	swap(b[0], b[5]);
	for (int i = 0; i < 6; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
