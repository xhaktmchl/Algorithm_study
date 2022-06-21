#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 03번 O] 크리스마스 카드 만들기
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐 재귀(합친 문자 갯수): 6개 중 4개의 문자열의 합이CHRISTMAS 인지
	//1)기저: 만약 4개의 문자열을 더했으면
	// CHRISTMAS 이면 카운트
	//중단
	//2)재귀: 문자열 6개 반복문
	// 방문 안했으면
	// 방문처리
	// 재귀(cnt+1, 문자열 합친 것)
	// 방문 취소
	// 3.출력: 카운트
시간복잡도: O()=
*/
int n,cnt;
string a[110];
string result;
bool visit[110];

void re(int cntStr,string curStr) {
	if (cntStr == 4) {
		if (curStr == "CHRISTMAS") {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			re(cntStr + 1, curStr + a[i]);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//2.완탐 재귀(합친 문자 갯수): 6개 중 4개의 문자열의 합이CHRISTMAS 인지
	//1)기저: 만약 4개의 문자열을 더했으면 
	// CHRISTMAS 이면 카운트
	//중단
	//2)재귀: 문자열 6개 반복문
	// 방문 안했으면 
	// 방문처리
	// 재귀(cnt+1, 문자열 합친 것)
	// 방문 취소
	re(0, result);
	// 3.출력: 카운트
	cout << cnt;
	return 0;
}
