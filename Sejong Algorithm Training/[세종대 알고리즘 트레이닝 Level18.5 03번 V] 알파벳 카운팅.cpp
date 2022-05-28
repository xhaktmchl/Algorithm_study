#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 03번 V] 알파벳 카운팅
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 문자 갯수 카운트
	//3.최빈 알파벳 탐색
	//최빈값이면 카운트 저장, 알파벳 저장
	//4.출력:
시간복잡도: O(6)=
*/
string input;
int cnt[50];
int maxC = -1;
char maxA;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> input;
	//2.완탐: 각 문자 갯수 카운트
	int len = input.size();
	for (int i = 0; i < len; i++) {
		cnt[input[i] - 'A']++;
	}
	//3.최빈 알파벳 탐색
	//최빈값이면 카운트 저장, 알파벳 저장
	for (int i = 0; i < 'Z'-'A'+1; i++) {
		if (cnt[i] > maxC) {
			maxA = 'A' + i;
			maxC = cnt[i];
		}
	}
	//4.출력:
	cout << maxA;
	return 0;
}
