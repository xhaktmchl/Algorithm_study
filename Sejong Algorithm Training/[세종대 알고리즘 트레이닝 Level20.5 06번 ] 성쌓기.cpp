#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 06번 ] 성쌓기
문제:
접근: 
풀이:
	//1.입력: 7개 배열
	//2.이중 반복 3,4,5,6 번 까지 출력
시간복잡도: O()=
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 7개 배열
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	//2.이중 반복 3,4,5,6 번 까지 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= 3+i; j++) {
			cout << a[j] << " ";

		}cout << '\n';
	}
	return 0;
}
