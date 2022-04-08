#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 레벨테스트 문제02 O] 1 to 9
문제: 
접근1: 완탐
시간복잡도: O(n)=1000
*/
int a[1010],cnt[1010];
int type, n;
bool flag = true;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	// 1.입력
	cin >> type >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++; // 숫자 갯수 카운트
	}
	// 2.완탐
	// 1) 타입1이면 갯수 카운트
	// 2) 타입2이면 중복 체크
	// 3.출력
	if (type == 1) {
		for (int i = 1; i <=9 ; i++) {
			cout << i << ":" << cnt[i] << "개" << '\n';
		}
	}
	else if (type == 2) {
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] >= 2) { flag = false; }
		}
		if (flag == 1) {cout << "중복없음" << '\n';}
		else { cout << "중복발견" << '\n'; }
	}
	return 0;
}
