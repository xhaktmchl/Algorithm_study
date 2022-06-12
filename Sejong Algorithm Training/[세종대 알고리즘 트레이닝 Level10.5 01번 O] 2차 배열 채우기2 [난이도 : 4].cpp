#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 01번 O] 2차 배열 채우기2 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5][5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.배열 채우기
	int n = 2;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[j][i] = n;
			n += 2;
		}
	}
	//2.출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
