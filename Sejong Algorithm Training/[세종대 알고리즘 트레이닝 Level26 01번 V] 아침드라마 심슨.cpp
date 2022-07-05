#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level26 01번 V] 아침드라마 심슨
문제:
접근:
풀이:
	//1.입력
	//2.완탐: 나이배열 탐색
	// 최댓값이면 갱신,
	//최솟값이면 갱신
	//3.출력:
시간복잡도: O()=
*/
int simData[10];
int maxN = 0, minN = 987987987;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 5; i++) {
		cin >> simData[i];
	}

	//2.완탐: 나이배열 탐색
	// 최댓값이면 갱신, 
	//최솟값이면 갱신
	for (int i = 0; i < 5; i++) {
		if (maxN < simData[i]) {
			maxN = simData[i];
		}
		if (minN > simData[i]) {
			minN = simData[i];
		}
	}
	//3.출력:
	cout << "MAX:" << maxN << '\n';
	cout << "MIN:" << minN;
	return 0;
}
