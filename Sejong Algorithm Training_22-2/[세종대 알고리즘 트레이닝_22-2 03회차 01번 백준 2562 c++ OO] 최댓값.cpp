#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 03회차 01번 백준 2562 c++ OO] 최댓값
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 일차 반복으로 탐색
	//만약 최댓값이면
	//최댓값 갱신, 인덱스 갱신
	//3.출력:최댓값, 인덱스

시간복잡도: O(n)= 
개념:
*/
int a[20];
int maxN, maxIdx;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	//2.완탐: 일차 반복으로 탐색
	//만약 최댓값이면 
	//최댓값 갱신, 인덱스 갱신
	maxN = a[0];
	for (int i = 0; i < 9; i++) {
		if (a[i] > maxN) {
			maxN = a[i];
			maxIdx = i;
		}
	}
	//3.출력:최댓값, 인덱스
	cout << maxN << '\n' << maxIdx+1 << '\n';
	return 0;
}
