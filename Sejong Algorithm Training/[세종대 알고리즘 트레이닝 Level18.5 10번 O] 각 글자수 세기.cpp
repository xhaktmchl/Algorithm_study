#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 10번 O] 각 글자수 세기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 문자 갯수 카운트
	//3.출력:
시간복잡도: O(200)=
*/
string a;
int cnt[200];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.완탐: 각 문자 갯수 카운트
	int len = a.size();
	for (int i = 0; i < len; i++) {
		cnt[a[i]]++;
	}
	//3.출력:
	for (int i = 'A'; i < 200; i++) {
		if (cnt[i] != 0) {
			cout << (char)i << ":" << cnt[i] << '\n';
		}
	}
	return 0;
}
