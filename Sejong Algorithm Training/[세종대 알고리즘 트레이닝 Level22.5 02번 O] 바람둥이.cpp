#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 02번 O] 바람둥이
문제:
접근: 
풀이: 완탐 재귀
	//1.입력
	//2.완탐 재귀: 2가지 경우를 n번 뽑기
	//1)기저: 만약 n번까지 뽑았다면
	//경로 출력
	//중단
	//2)재귀:
	//x선택
	//o선택
시간복잡도: O(2^n)=
*/
int n;
string path;

void re(int idx) {
	if (idx == n) {
		cout << path << '\n';
		return;
	}

	path.push_back('x');
	re(idx + 1);
	path.pop_back();

	path.push_back('o');
	re(idx + 1);
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.완탐 재귀: 2가지 경우를 n번 뽑기
	//1)기저: 만약 n번까지 뽑았다면 
	//경로 출력
	//중단
	//2)재귀: 
	//x선택
	//o선택
	re(0);
	return 0;
}
