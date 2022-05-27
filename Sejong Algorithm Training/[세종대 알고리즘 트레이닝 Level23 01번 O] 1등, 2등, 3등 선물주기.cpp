#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 01번 O] 1등, 2등, 3등 선물주기
문제:
접근: 4개중 3개 뽑는 순열 4p3
풀이: 완탐 재귀, 순열
	//1.입력
	//2.완탐 재귀: 4개중 3개 뽑는 순열 4p3
	//1)기저: 만약 3개를 뽑았다면
	//순열 출력
	//중단
	//2)재귀: 0~3 인덱스 문자 탐색
	//방문검사 : 방문 안했으면
	//방문처리
	//경로에 문자 추가
	//재귀
	//방문 취소
	//경로에 문자 팝
시간복잡도: O(4^3)=
*/
char input[10];
string path;
bool visit[10];

void re(int idx) {
	if (idx == 3) {
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < 4; i++ ) {
		if (!visit[i]) {
			visit[i] = 1;
			path.push_back(input[i]);
			re(idx + 1);
			visit[i] = 0;
			path.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> input;
	//2.완탐 재귀: 4개중 3개 뽑는 순열 4p3
	//1)기저: 만약 3개를 뽑았다면
	//순열 출력
	//중단
	//2)재귀: 0~3 인덱스 문자 탐색
	//방문검사 : 방문 안했으면
	//방문처리
	//경로에 문자 추가
	//재귀
	//방문 취소
	//경로에 문자 팝
	re(0);
	return 0;
}
