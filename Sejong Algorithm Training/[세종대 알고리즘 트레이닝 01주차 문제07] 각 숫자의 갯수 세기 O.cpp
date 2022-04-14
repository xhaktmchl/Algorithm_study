#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 01주차 문제07] 각 숫자의 갯수 세기 O
문제: 
접근: 
풀이: 완탐, 갯수 배열에 메모이제이션
시간복잡도: 
*/
int a[10] = { 1,5,2,2,2,3,1,5 };
int cnt[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 배열 완탐 탐색
	// 각 숫자 카운트
	for (int i = 0; i < 8; i++) {
		cnt[a[i]]++;
	}
	//출력
	for (int i = 1; i <= 5; i++) {
		cout << i << ": " << cnt[i] << "개" << '\n';
	}
	return 0;
}
