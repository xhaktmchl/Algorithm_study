#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 05번 V] 사랑해요 MCD
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 문자열 배열 탐색하면 MCD 있는지 조회
	//1)str.find로 조회
	//2)만약 결과값이 -1이면 중단
	//3)아니면 카운트
	//3.출력: 카운트
시간복잡도: O()=
*/
string a[10];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	//2.완탐: 문자열 배열 탐색하면 MCD 있는지 조회
	//1)str.find로 조회
	//2)만약 결과값이 -1이면 중단
	//3)아니면 카운트
	for (int i = 0; i < 5; i++) {
		int idx = -1;
		while (1) {
			idx = a[i].find("MCD", idx + 1);
			if (idx == -1) {
				break;
			}
			cnt++;
		}
	}
	//3.출력: 카운트
	cout << cnt;
	return 0;
}
