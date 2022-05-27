#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 04번 OO] 산타소년단
문제:
접근:
풀이: 완탐 재귀, 순열
	//1.입력
	//2.완탐 재귀: 5명중 n명 뽑는 순열
	//1)기저: 만약 n번째 까지 뽑았으면
	//예외: B멤버 포함 안돼있는 것
	//카운트
	//중단
	//2)재귀: 0~4번 멤버까지탐색
	//방문검사: 방문했으면 넘어감
	//방문안했으면 방문처리
	//재귀
	//방문 취소
	//3.출력: 카운트
시간복잡도: O(n*n)=10000
*/
int n;
char input[10] = "BTSKR";
string path;
bool visit[10];
int cnt = 0;

void re(int idx) {
	if (idx == n) {
		if (visit[0]) {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (visit[i]) { continue; }
		visit[i] = 1;
		re(idx + 1);
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.완탐 재귀: 5명중 n명 뽑는 순열
	//1)기저: 만약 n번째 까지 뽑았으면
	//예외: B멤버 포함 안돼있는 것
	//카운트
	//중단
	//2)재귀: 0~4번 멤버까지탐색
	//방문검사: 방문했으면 넘어감
	//방문안했으면 방문처리
	//재귀
	//방문 취소
	re(0);
	//3.출력: 카운트
	cout << cnt;
	return 0;
}
