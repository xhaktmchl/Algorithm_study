#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 08번] 마을사람들 찾기 V
문제:
접근:
풀이:
시간복잡도: O(n*n)=
*/
string vect = "BTKIGZ";
char target[10];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> target[i];
	}
	//2.완탐: 입력받은 각 문자가 vect에 있는지 find
	//있으면 갯수 카운트
	// find(시작주소, 끝주소, 찾는 값) : 없으면 end()반환
	for (int i = 0; i < 4; i++) {
		if (find(vect.begin(), vect.end(), target[i]) != vect.end()) {
			cnt++;
		}
	}
	//3.출력: 갯수
	cout << cnt << '\n';
	return 0;
}
