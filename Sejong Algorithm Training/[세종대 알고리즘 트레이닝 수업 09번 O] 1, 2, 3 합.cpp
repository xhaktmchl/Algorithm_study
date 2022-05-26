#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업 09번 O] 1, 2, 3 합
문제:
접근:
풀이: 완탐 재귀
	//1.입력
	//2.재귀
	//1)기저: 만약 합이 n이면
	//카운트
	//중단
	//2)재귀:1~3 합
	//예외처리:합이 n보다 크면 넘어감
	//재귀
	//3.출력:경우의 수
시간복잡도: O(3^)=??
*/
int n, cnt = 0;

//2.재귀
//1)기저: 만약 합이 n이면
//카운트
//중단
//2)재귀:1~3 합
//예외처리:합이 n보다 크면 넘어감
//재귀
void re(int sum) {
	if (sum == n) {
		cnt++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum + i > n) { continue; }
		re(sum + i);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.재귀
	//1)기저: 만약 합이 n이면
	//카운트
	//중단
	//2)재귀:1~3 합
	//예외처리:합이 n보다 크면 넘어감
	//재귀
	re(0);
	//3.출력:경우의 수
	cout << cnt;
	return 0;
}
