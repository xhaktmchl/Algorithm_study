#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 05번 O] 양쪽에서 아이찾기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.왼쪽부터 탐색
	//찾으면 인덱스 저장
	//중단
	//3.오른부터 탐색
	//찾으면 인덱스 저장
	//중단
	//출력: 두 인덱스 차이의 절댓값
시간복잡도: O(9*2)=
*/
char a[15] = "ATKPTCABC";
char tar1, tar2;
int loc1, loc2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> tar1 >> tar2;
	//2.왼쪽부터 탐색
	//찾으면 인덱스 저장
	//중단
	for (int i = 0; i < 9; i++) {
		if (a[i] == tar1) {
			loc1 = i;
			break;
		}
	}
	//3.오른부터 탐색
	//찾으면 인덱스 저장
	//중단
	for (int i = 9; i >= 0; i--) {
		if (a[i] == tar2) {
			loc2 = i;
			break;
		}
	}
	//출력: 두 인덱스 차이의 절댓값
	cout << abs(loc1 - loc2);
	return 0;
}
