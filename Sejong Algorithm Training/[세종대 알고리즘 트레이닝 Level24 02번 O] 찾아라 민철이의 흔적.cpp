#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 02번 O] 찾아라 민철이의 흔적
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 일차반복으로 각 문자열에서 이름 조회
	//있으면 O
	//없으면 X
시간복잡도: O()=
*/
string name;
int n;
string a[200];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> name >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//2.완탐: 일차반복으로 각 문자열에서 이름 조회
	//있으면 O
	//없으면 X
	for (int i = 0; i < n; i++) {
		if ((int)a[i].find(name) != -1) {
			cout << "O" << '\n';
		}
		else { cout << "X" << '\n'; }
	}
	return 0;
}
