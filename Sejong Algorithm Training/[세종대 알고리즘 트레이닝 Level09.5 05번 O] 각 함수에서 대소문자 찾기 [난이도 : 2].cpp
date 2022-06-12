#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 05번 O] 각 함수에서 대소문자 찾기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[5][5];
int cntU = 0, cntL=0;

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
}

void findUpper() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] >= 'A' && a[i][j] <= 'Z') { cntU++; }
		}
	}

	cout << "대문자" << cntU << "개" << '\n';
}

void findLower() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] >= 'a' && a[i][j] <= 'z') { cntL++; }
		}
	}

	cout << "소문자" << cntL << "개" << '\n';
}


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	input();
	findUpper();
	findLower();
	return 0;
}
