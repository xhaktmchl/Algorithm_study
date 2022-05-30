#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 01번 O] 함수와 포인터
문제:
접근: 
풀이: 
	//1.입력
	//2.횜수로 최대 최소 값 구하기
	//3.출력
시간복잡도: O(5)=
*/
int a[10];
int maxN, minN;

void BBQ() {
	for (int i = 0; i < 5; i++) {
		maxN = max(maxN, a[i]);
		minN = min(minN, a[i]);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	//2.횜수로 최대 최소 값 구하기
	maxN = a[0];
	minN = a[0];
	BBQ();
	//3.출력
	cout << "a=" << maxN << '\n';
	cout << "b=" << minN;
	return 0;
}
