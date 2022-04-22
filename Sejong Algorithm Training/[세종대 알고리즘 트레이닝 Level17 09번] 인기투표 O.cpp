#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 09번] 인기투표 O
문제:
접근:
풀이:
시간복잡도: O(n*n*m)=
*/
int vect[5][5] = {
	{3,7,4},
	{2,2,4},
	{2,2,5}
};
int target[5];
int cnt[5], maxN=-1, maxNum;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	for (int i = 0; i < 3; i++) {
		cin >> target[i];
	}
	//2.완탐: 3중 반복, target숫자 vect배열에 있는지 탐색
	//각 숫자 카운트
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 3; p++) {
				if (vect[i][j] == target[p]) {
					cnt[p]++;
				}
			}
		}
	}
	//3.출력 최대빈도 숫자
	for (int i = 0; i < 3; i++) {
		if (maxN < cnt[i]) {
			maxN = cnt[i];
			maxNum = target[i];
		}
	}
	cout << maxNum << '\n';
	return 0;
}
