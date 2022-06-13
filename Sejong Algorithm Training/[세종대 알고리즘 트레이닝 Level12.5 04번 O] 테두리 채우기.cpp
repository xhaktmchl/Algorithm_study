#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level12.5 04번 O] 테두리 채우기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10][10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	
	//좌우
	for (int i = 0; i < 5; i++) {
		a[i][0] = n;
		a[i][4] = n;
	}
	//하상
	for (int i = 0; i < 5; i++) {
		a[4][i] = n;
		a[0][i] = n;
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == 0) { cout << "_"; }
			else { cout << a[i][j]; }
		}cout << '\n';
	}
	return 0;
}
