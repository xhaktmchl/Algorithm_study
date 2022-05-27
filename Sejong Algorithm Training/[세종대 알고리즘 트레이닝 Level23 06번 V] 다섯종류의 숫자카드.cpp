#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 06번 V] 다섯종류의 숫자카드
문제:
접근:
풀이: 완탐 재귀, 중복순열
	//1.입력
	//2.재귀
	//1)기저: 만약 4번째 문자까지 채웠다면
	//카운트
	//중단
	//2)재귀: 5개의 문자
	//예외처리: 경로에 문자가 존재하고,,전 숫자랑 3초과인 경우
	//경로에 문자 추가
	//재귀
	//경로에 문자 팝
	//3.출력: 카운트
	return 0;
시간복잡도: O(n*n)=10000
*/
char input[10];
int cnt = 0;
string path;

void re(int idx) {
	if (idx == 4) {
		cnt++;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (path.size()!=0 && abs((input[i] - path[idx-1])) > 3) { continue; }
		path.push_back(input[i]);
		re(idx + 1);
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> input;
	
	//2.재귀
	//1)기저: 만약 4번째 문자까지 채웠다면
	//카운트
	//중단
	//2)재귀: 5개의 문자
	//예외처리: 경로에 문자가 존재하고,,전 숫자랑 3초과인 경우
	//경로에 문자 추가
	//재귀
	//경로에 문자 팝
	re(0);
	//3.출력: 카운트
	cout << cnt;
	return 0;
}
