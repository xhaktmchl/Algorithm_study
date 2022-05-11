#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 03번] 카운팅값 찾기 O
문제:
접근:
풀이:
시간복잡도: O(3*5)=
*/
int a[3][5] = {
	{1, 3, 3, 5, 1},
	{3, 6, 2, 4, 2},
	{1, 9, 2, 6, 5}
};
int n;
int cnt[15];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력:n
	cin >> n;
	//2.완탐: 각 숫자 갯수 카운트
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j< 5; j++) {
			cnt[a[i][j]]++;
		}
	}
	//3.출력: 카운트 배열에서 갯수가 n이면 오름차순 출력
	for (int i = 1; i <= 9; i++) {
		if (cnt[i] == n) {
			cout << i << " ";
		}
	}
	return 0;
}
