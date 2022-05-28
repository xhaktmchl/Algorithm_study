#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 06번 O] 사법고시 합격자 발표
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 합격자 명단에서
	//4명의 사람 탐색
	//합격햇으면 flag배열에 1저장
	//3.출력
시간복잡도: O(2*3*4)=
*/
int win[5][5] = {
	{3,5,1},
	{4,2,6}
};
int people[5];
bool flag[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> people[i];
	}
	//2.완탐: 합격자 명단에서 
	//4명의 사람 탐색
	//합격햇으면 flag배열에 1저장
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 4; p++) {
				if (people[p] == win[i][j]) {
					flag[p] = 1;
				}
			}
		}
	}
	//3.출력
	for (int i = 0; i < 4; i++) {
		if (flag[i]) { cout << people[i] << "번 합격"<<'\n'; }
		else { cout << people[i] << "번 불합격" << '\n'; }
	}
	return 0;
}
