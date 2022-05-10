#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 09번] 비트배열에서 min값의 인덱스와 값 구하기 O
문제:
접근:
풀이:
시간복잡도: O(n)=6
*/
int mask[10] = { 1,0,1,0,1,0 };
int a[10], minN, minIdx = -1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 마스킹
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	//2.완탐: 마스킹 된 곳중 최솟값
	// 작으면 최솟값, 인덱스 갱신
	minN = a[0];
	minIdx = 0;
	for (int i = 0; i < 6; i++) {
		if (mask[i] == 1) {
			if (a[i] < minN) {
				minN = a[i];
				minIdx = i;
			}
		}
	}
	//3.출력: 
	cout << "arr[" << minIdx << "]=" << minN;
	return 0;
}
