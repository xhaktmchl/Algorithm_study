#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 01번] 성실한 직원 찾기 V
문제:
접근:
풀이:
시간복잡도: O(n*n)=
*/
int a[3][4] = {
	{65000, 35, 42, 70},
	{70, 35, 65000, 1300},
	{65000, 30000, 38, 42}
};

int cnt[100000];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.완탐:이중 반복으로 각 숫자 배열에 카운트
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cnt[a[i][j]]++;
		}
	}
	//2.출력: 가장 빈도수 높은 id 인덱스 값 
	cout << (max_element(cnt, cnt + 65536) - cnt);
	return 0;
}
