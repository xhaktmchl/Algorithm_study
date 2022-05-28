#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 01번 O] 가족을 찾아라
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 문자 갯수 카운트
	//3.출력: 문자중 3개 이상인 것 있으면
	//없으면
시간복잡도: O(2*3)=
*/
char input[10]="GKG";
int cnt[50];
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 3; i < 6; i++) {
		cin >> input[i];
	}
	//2.완탐: 각 문자 갯수 카운트
	for (int i = 0; i < 6; i++) {
		cnt[input[i] - 'A']++;
		if (cnt[input[i] - 'A'] >= 3) {
			flag = 1;
		}
	}
	//3.출력: 문자중 3개 이상인 것 있으면
	//없으면
	if (flag) { cout << "있음"; }
	else { cout << "없음"; }
	return 0;
}
