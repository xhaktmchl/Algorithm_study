#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 03번 O] ABC초콜릿
문제:
접근: 
풀이: 완탐재귀
	//1.입력
	//2.완탐 재귀:3개의 알파벳으로 n 번뽑기
	//1)기저조건: 만약 n번째 뽑기면
	//카운트
	//중단
	//2)재귀
	//ABC탐색
	//예외처리:2인덱스 번째 문자부터 뒤에 2개의 연속된 같은 문자 나옴
	//경로에 문자추가
	//재귀
	//경로에 문자 팝
	//3.출력
시간복잡도: O(3^n)=
*/
int n, cnt = 0;
string input = "ABC";
string path;

//2.완탐 재귀:3개의 알파벳으로 n 번뽑기
//1)기저조건: 만약 n번째 뽑기면
//카운트
//중단
//2)재귀
//ABC탐색
//예외처리:2인덱스 번째 문자부터 뒤에 2개의 연속된 같은 문자 나옴 
//경로에 문자추가
//재귀
//경로에 문자 팝
void re(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (idx >= 2) {
			if (input[i] == path[idx - 1] && input[i] == path[idx - 2]) {
				continue;
			}
		}
		path.push_back(input[i]);
		re(idx + 1);
		path.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> n;
	//2.완탐 재귀:3개의 알파벳으로 n 번뽑기
	//1)기저조건: 만약 n번째 뽑기면
	//카운트
	//중단
	//2)재귀
	//ABC탐색
	//예외처리:2인덱스 번째 문자부터 뒤에 2개의 연속된 같은 문자 나옴 
	//경로에 문자추가
	//재귀
	//경로에 문자 팝
	re(0);
	//3.출력
	cout << cnt;
	return 0;
}
