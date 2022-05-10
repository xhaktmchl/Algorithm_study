#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 07번] 도와주세요 다이어트 O
문제:
접근:
풀이:
시간복잡도: O(n)=4
*/
int levelTable[5][5] = {
	{10,20},
	{30,60},
	{100,150},
	{200,300}
};

int kal[10];
int cnt[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 6; i++) {
		cin >> kal[i];
	}
	//2.완탐: 칼로리 각 단계 카운트
	for (int i = 0; i < 6; i++) {
		if (kal[i] >= 10 && kal[i] <= 20) {
			cnt[0]++;
		}
		else if (kal[i] >= 30 && kal[i] <= 60) {
			cnt[1]++;
		}
		else if (kal[i] >= 100 && kal[i] <= 150) {
			cnt[2]++;
		}
		else if (kal[i] >= 200 && kal[i] <= 300) {
			cnt[3]++;
		}

	}
	//3.출력: 각 단계별 갯수
	for (int i = 0; i < 4; i++) {
		cout << "lev" << i << ":" << cnt[i] << '\n';
	}
	return 0;
}
