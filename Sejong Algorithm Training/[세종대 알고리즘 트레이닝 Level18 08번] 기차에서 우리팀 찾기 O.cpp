#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 08번] 기차에서 우리팀 찾기 O
문제:
접근: 완탐,
풀이:
시간복잡도: O(n*m)=8*3
*/
int train[] = { 3, 7, 6, 4, 2, 9, 1, 7 };
int team[5];
int minIdx = 10, maxIdx = -1;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 팀
	for (int i = 0; i < 3; i++) {
		cin >> team[i];
	}
	//2.완탐: 팀 번호 탐색
	// team배열처럼 같은순서 같이 붙어있으면 찾으면 최소값, 최댓값 인덱스 저장
	for (int i = 0; i < 8; i++) {
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			if (train[i + j] == team[j]) {
				minIdx = min(minIdx, i + j);
				maxIdx = max(maxIdx, i + j);
				cnt++;
			}
		}
		if(cnt==3){
			break;
		}
	}
	//3.출력:
	cout << minIdx << "번~" << maxIdx << "번 칸";
	return 0;
}
