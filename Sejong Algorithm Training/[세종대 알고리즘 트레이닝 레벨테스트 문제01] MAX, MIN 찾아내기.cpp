#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 레벨테스트 문제01] MAX, MIN 찾아내기 
문제: 
접근1: 완탐
시간복잡도: O(n)
*/
int a[10];
int minN, maxN;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	// 1.입력
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	// 2.완탐으로 최대,최솟값 저장
	minN = a[0];
	maxN = a[0];
	for (int i = 0; i < 7; i++) {
		minN = min(minN, a[i]);
		maxN = max(maxN, a[i]);
	}
	// 3.출력
	cout << "MAX=" << maxN << '\n' << "MIN=" << minN<<'\n';
	return 0;
}
