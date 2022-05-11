#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 06번] 블랙리스트 O
문제:
접근: 완탐,
풀이:
시간복잡도: O(3*3*4)=
*/
char town[5][5] = {
	"CDA",
	"BMZ",
	"QPO"
};
string black;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> black;
	//2.완탐: town배에 블랙리스트 있는지 탐색
	// 있으면 카운트
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < black.size(); p++) {
				if (black[p] == town[i][j]) {
					cnt++;
				}
			}
		}
	}
	//3.출력: 리스트 인원수
	cout << cnt<<"명";
	return 0;
}
