#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 05번 V] 미안하다 친구야
문제:
접근: 
풀이: 완탐재귀
	//1.입력: 뺄 친구
	//2.완탐 재귀: 4길이 순열
	//1)기저조건: 4번째 길이면
	//경로출력
	//중단
	//2)재귀: 5개의 문자 순서대로
	//예외: 만약 뺄 친구 면 제외
	//예외: 방문했으면 제외
	//방문처리
	//경로에 문자 추가
	//재귀
	//방문취소
	//경로에 문자 팝
	//3.출력
시간복잡도: O(4^4)=
풀이2: 순열 c++라이브러리 (시도 안해봄)
*/
char tar;
string path;
string ar = "EWABC";
bool visit[10];

void re(int idx) {
	if (idx == 4) {
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (ar[i] == tar) { continue; }
		if (visit[i] == 1) { continue; }
		visit[i] = 1;
		path.push_back(ar[i]);
		re(idx + 1);
		visit[i] = 0;
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력: 뺄 친구
	cin >> tar;
	//2.완탐 재귀: 4길이 순열
	//1)기저조건: 4번째 길이면
	//경로출력
	//중단
	//2)재귀: 5개의 문자 순서대로
	//예외: 만약 뺄 친구 면 제외
	//예외: 방문했으면 제외
	//방문처리
	//경로에 문자 추가
	//재귀
	//방문취소
	//경로에 문자 팝
	re(0);
	//3.출력
	return 0;
}
