#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23 02번 O] 다툰친구 B와 T
문제:
접근: 
풀이: 완탐재귀
	//1.입력
	//2.완탐재귀
	//1)기저조건: 4번째 인덱스이면
	//카운트
	//중단
	//2)재귀
	// 문자 엠티일때 예외처리
	//만약 현재가 T인데 다음이 B 예외처리
	//만약 현재가 B인데 다음이 T 예외처리
	//경로에 문자 추가
	//재귀
	//경로에 문자 팝
	//3.출력:
시간복잡도: O(4^4)=
*/
string input;
string path;
int cnt = 0;

void re(int idx) {
	if (idx == 4) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (idx != 0) {
			if (input[i] == 'B' && path.back() == 'T') { continue; }
			if (input[i] == 'T' && path.back() == 'B') { continue; }
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
	cin >> input;
	//2.완탐재귀
	//1)기저조건: 4번째 인덱스이면 
	//카운트
	//중단
	//2)재귀
	//만약 현재가 T인데 다음이 B 예외처리
	//만약 현재가 B인데 다음이 T 예외처리
	//경로에 문자 추가
	//재귀
	//경로에 문자 팝
	re(0);
	//3.출력:
	cout << cnt;
	return 0;
}
