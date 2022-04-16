#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 04번] 누적점핑 O
문제:
접근:
풀이:
시간복잡도: O()
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> a[0] >> a[1];
	//2.두수의 곱 배열
	for (int i = 1; i < 6; i++) {
		a[i + 1] = a[i] * a[i - 1];
	}
	//3.출력: 마지막 인덱스
	cout << a[5];
	return 0;
}
